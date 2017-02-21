#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 
 * Approach/Algorithm: 
 * 1. Read 48 bytes of data from the file to a buffer(read_bytes) until you hit EOF. 
      This corresponds to 32 12-bit values. Ignore last odd-th 12-bit value. 
 * 2. Extract 2 values at a time from this buffer and sort them using another buffer(sort_array). 
      sort_array has a size of 34 elements and each element is 16-bits(unsgined short) long.
 * 3. Insertion sort is used to sort elements. The last 32 elements are always in the sorted order. 
      So, everytime two new values are read, only these two values are sorted.   
 * 4. Print values to file. sort_array would contain the 32 largest values from the input file. 
      read_bytes would also contain the last 32 values read from the input file.
*/
 
/* 
 * Design decisions/tradeoffs and any optimizations for speed, memory, etc:
 * 1. We use 48 bytes for reading the data from the file, and (32+2)*2 bytes for storing and sorting. 
      This way a very small sized buffer is used for storing the data. This might mean lot more reads from the file/IO. 
      Optimized for less memory here. 
 * 2. Not much focus has been given to future extensibility of the program. The program is very tightly written for smaller numbers.
   3. Not many error checks(e.g NULL pointer etc.) They will lead to additional instructions, bloated code. 
      We are running in very closed system. In fact I would like to get rid of the check for odd number of 12-bit values.  
   4. There are lot of functions written in the code. Function call comes with some overhead. 
      But, then they ease the readability and maintainance of the code. I have given lot of importance to that.
      The best way to measure these kinds of things would be calculate the time it takes and then optimize.
   5. Functions also help to abstract some of the specifc parts: e.g.IO has been moved to smaller functions.  
      These three functions do the entire job: sort_12bit_values(), insertion_sort(), extract_2_values()
      Idea is if we find a better sorting algo replacing the current one should be isolated to just one function. 
   6. I thought lot about Inlining some of the functions. But then they would increase the code size.  
   7. Instead of using 2 bytes for 1 value for storing the orted data, we could have used 3 bytes and stored 2 values. 
 *    But, it might mean more compressing and uncompressing. More space used to make it faster here.
   8. Insertion sort: Is one of the most efficient algorithms for sorting already almost sorted data. 
      Real world data is mostly almost sorted.
   9. Almost no comments in the middle of the code. I like it when the code is very self explanatory.
 */


#define TRUE   1
#define FALSE  0

#define PARTIAL_VAL_SET_MASK   0x01
#define CARRY_BYTE_SET_MASK    0x02
#define NO_OF_VALUES_TO_STORE    32
#define NO_OF_BYTES_CORRESPONDING_32_TO_VALUES  ((NO_OF_VALUES_TO_STORE * 3)/2)

static int sort_12bit_values();
static int extract_2_values( unsigned char* read_bytes,unsigned short* no_processed_bytes,unsigned short* sort_array,unsigned short* sort_array_index);
static int insertion_sort(unsigned short* array,unsigned short length,  unsigned short sorted_begin_index);
static int get_data_from_file(size_t* result,unsigned char *read_bytes);
static int print_all_values_to_file(unsigned short* array, unsigned short len, unsigned char* read_bytes, size_t result,unsigned short* sort_array);

static FILE*   p_input_file = NULL;
static FILE*   p_output_file = NULL;   

#if 0
int main(int argc, char** argv)
{
    long size;
    
    if(argc < 3)
    {
        printf("ERROR: The program needs an input file and and and output file name. Looks like it has not been provided  \n");
        return 1;
    }
                
    printf("The input file name = %s \n",argv[1]);
    printf("The output file name = %s \n",argv[2]);

    
    p_input_file = fopen( argv[1] , "rb" );
    if ( p_input_file == NULL ) 
    {
        printf("ERROR: While opening the input file %s\n",argv[1]); 
        return 1;
    }

    fseek(p_input_file, 0L, SEEK_END);
    size = ftell(p_input_file);
    if(size == 0)
    {
        printf("ERROR: Size of the input file %s is zero. Cant do much. \n",argv[1]); 
        fclose (p_input_file);             
        return 0;       
        
    }
    rewind(p_input_file);
                
    p_output_file = fopen( argv[2] , "w" );
    if ( p_output_file == NULL ) 
    {
        printf("ERROR: While opening the output file %s\n",argv[2]); 
        fclose (p_input_file);   
        return 1;
    }
    
    
    
    if(sort_12bit_values() != 0)
    {
        printf("ERROR: Something went wrong during generation of max 32 values.\n");
    }                              
    printf("SUCCESS: Sorting 12-bit values from the file \n"); 
    
    fclose (p_input_file);             
    fclose (p_output_file);     
    
    return 0;          
}
#endif

static int sort_12bit_values()
{
    unsigned short   sort_array[NO_OF_VALUES_TO_STORE+2] = {};
    unsigned char    read_bytes[NO_OF_BYTES_CORRESPONDING_32_TO_VALUES] = {};
    unsigned short   sort_array_index = 0;
    unsigned short   no_processed_bytes = 0; 
    unsigned char    min_no_values_read = FALSE;  
    size_t           result = 0;
                                                
    while(1)
    {
        get_data_from_file(&result,read_bytes);
     
        printf("The value read result = %d \n",result);

        result = result - (result % 3);

        printf("The value read result = %d \n",result);
        if( result <= NO_OF_BYTES_CORRESPONDING_32_TO_VALUES)
        {
            while( (no_processed_bytes) < result )
            {
                extract_2_values(read_bytes,&no_processed_bytes,sort_array,&sort_array_index);
                insertion_sort(sort_array,34,2);
                sort_array_index = 0;
            }              
                                                
        }

        /* Exit condition */                        
        if(result != NO_OF_BYTES_CORRESPONDING_32_TO_VALUES) 
        {
            if(min_no_values_read == TRUE)
                print_all_values_to_file(sort_array,(NO_OF_VALUES_TO_STORE),read_bytes,result,sort_array);
            else
                print_all_values_to_file(sort_array,(((result*2)/3)),read_bytes,result,sort_array);
            break;
        }
                        
        min_no_values_read = TRUE; no_processed_bytes = 0;  
    }
    
    return 0;
}




static int extract_2_values( unsigned char* read_bytes,unsigned short* no_processed_bytes,unsigned short* sort_array,unsigned short* sort_array_index)
{

    unsigned char    carry_byte = 0;
    unsigned short   partial_value = 0;
    unsigned char    flag = 0;
    unsigned char    no_values_to_extract = 2;
    
    while(no_values_to_extract)
    {
        printf("The value of read_bytes[%d] = %d \n",(*no_processed_bytes),read_bytes[(*no_processed_bytes)]);
        if(!(flag & CARRY_BYTE_SET_MASK) && !(flag & PARTIAL_VAL_SET_MASK))
        {
            partial_value = read_bytes[(*no_processed_bytes)];
            flag |= PARTIAL_VAL_SET_MASK;
        }
        else if(!(flag & CARRY_BYTE_SET_MASK) && (flag & PARTIAL_VAL_SET_MASK))
        {
            sort_array[*sort_array_index] =  (partial_value << 4) | ((read_bytes[(*no_processed_bytes)] & 0xF0) >> 4);
            printf("file read: the value of sort_array[%d] = %d \n",*sort_array_index,sort_array[*sort_array_index]);
            carry_byte = (read_bytes[*no_processed_bytes]) & 0x0F;
            flag &= ~PARTIAL_VAL_SET_MASK; 
            flag |=  CARRY_BYTE_SET_MASK;
            no_values_to_extract--;
            (*sort_array_index)++;
                                                                                
        }
        else if((flag & CARRY_BYTE_SET_MASK) && !(flag & PARTIAL_VAL_SET_MASK))
        {
            sort_array[*sort_array_index] = (carry_byte << 8) | read_bytes[*(no_processed_bytes)];
            printf("file read: the value of sort_array[%d] = %d \n",*sort_array_index,sort_array[*sort_array_index]);      
            flag &= ~CARRY_BYTE_SET_MASK; 
            no_values_to_extract--;
            (*sort_array_index)++;
        }
        else{}

                                                                
        (*no_processed_bytes)++;
    }

    return 0;   
}
 
static int insertion_sort(unsigned short* array, unsigned short length,  unsigned short sorted_begin_index)
{
    unsigned short element;
    short i = 0;
    short j = 0;
                
    for (i = sorted_begin_index-1; i >= 0; i--)
    {
        element = array[i];
        for( (j = i+1); ( (j < length ) && (element > array[j]) ) ; j++ )
        {
            array[j-1] = array[j];
        }
        array[j-1] = element;
    }

    return 0;
}

static int print_all_values_to_file(unsigned short* array, unsigned short len, unsigned char* read_bytes, size_t result,unsigned short* sort_array)
{
    unsigned short   sort_array_index = 0;
    unsigned short   i = 0;
    unsigned short   no_processed_bytes = 0;   
    unsigned short   offset = 0;
    
    if(p_input_file && p_output_file)
    {
        fprintf(p_output_file,"--Sorted Max 32 Values--\n");  
        for(i = (NO_OF_VALUES_TO_STORE + 2 - len); i < NO_OF_VALUES_TO_STORE+2; i++)
        {
            fprintf(p_output_file,"%d\n",array[i]);
        }

        if((len != (NO_OF_VALUES_TO_STORE)))
        {
            no_processed_bytes = NO_OF_BYTES_CORRESPONDING_32_TO_VALUES - result;
            offset = 0;
        }   
        else
            offset = result;


        fprintf(p_output_file,"--Last 32 Values--\n");  
        while( NO_OF_BYTES_CORRESPONDING_32_TO_VALUES > no_processed_bytes )
        {
            extract_2_values(read_bytes,&offset,sort_array,&sort_array_index);
            fprintf(p_output_file,"%d\n",sort_array[sort_array_index-2]);
            fprintf(p_output_file,"%d\n",sort_array[sort_array_index-1]);

            no_processed_bytes = no_processed_bytes+3;
                           
            if(offset >= NO_OF_BYTES_CORRESPONDING_32_TO_VALUES)
            {
                offset  = 0;
            }
        }              
    }
                
    return 0;
}

static int get_data_from_file(size_t* result,unsigned char *read_bytes)
{
    *result = fread(read_bytes,  sizeof(unsigned char), NO_OF_BYTES_CORRESPONDING_32_TO_VALUES, p_input_file); 

    return 0;
}
