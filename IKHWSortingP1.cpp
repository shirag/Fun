/*


 * IKHWSortingP1.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: raghav
 */

#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"

/*
 * The cool part of this problem is that it shows that patitioning in quick sort is a very generic problem.
 * You have an index at which and below that index you have all values belonging to a criterion.
 * Above the index you have values not belonging to that criterion.
 *
 * In the following case lastEndIndex indicates the index below which(including) you have all even values.
 * In the quick sort problem lastEndIndex indicates the index below which(including) you have all values less than or equal to pivot val.
 *
 * Lomuto partition scheme is used.
 */
vector<int> IKSolution::groupNumbers(vector<int> intArr)
{

    int lastEndIndex = -1;
    int currIndex = 0;

    for(currIndex = 0; currIndex < intArr.size() - 1; currIndex++)
    {
        if(!(intArr[currIndex]%2))
        {
            lastEndIndex++;
            int temp = intArr[currIndex];
            intArr[currIndex] = intArr[lastEndIndex];
            intArr[lastEndIndex] = temp ;
        }

    }

    if(!(intArr[currIndex]%2))
    {
        lastEndIndex++;
        int temp = intArr[currIndex];
        intArr[currIndex] = intArr[lastEndIndex];
        intArr[lastEndIndex] = temp ;
    }

    return intArr;

}

/*********************************************************************************************************************/

int partition(vector<int>& a, int low, int high)
{

    int lastEndIndex = low - 1;

    int pivot_loc = high;
    int currIndex;

    for(currIndex = low; currIndex < high; currIndex++)
    {
        if( a[currIndex] <= a[pivot_loc] )
        {
            lastEndIndex++;
            int temp = a[currIndex];
            a[currIndex] = a[lastEndIndex];
            a[lastEndIndex] = temp;

        }
    }

    lastEndIndex++;
    int temp = a[currIndex];
    a[currIndex] = a[lastEndIndex];
    a[lastEndIndex] = temp;


    DEBUG_DEBUG(cout << "Value at " << lastEndIndex << " " << a[lastEndIndex] << " is at its final location \n");
    return lastEndIndex;
}


void quickSortUtil(vector<int>& a, int low, int high)
{
    DEBUG_TRACE(cout << "low = " << low << " high = " << high << " \n");
    if(high <= low)
        return;

    int pivot = partition(a, low, high);

    quickSortUtil(a,low, (pivot - 1));
    quickSortUtil(a, (pivot + 1), high);

}

/*
 * For partitioning we use Lomuto partition scheme.  */

vector<int> IKSolution::quickSort(vector<int>& a)
{
    quickSortUtil(a, 0, (a.size() - 1));
    return a;
}



/*******************************************************************************************************************************/

void printNutsNBolts(vector<int> nutsa, vector<int> boltsa)
{
    DEBUG_DEBUG(cout  << " N ");
    for(auto it : nutsa)
    {
        DEBUG_DEBUG(cout  << " " << it  );
    }
    DEBUG_DEBUG(cout  << "\n");

    DEBUG_DEBUG(cout  << " B ");
    for(auto it : boltsa)
    {
        DEBUG_DEBUG(cout  << " " << it  );
    }
    DEBUG_DEBUG(cout  << "\n");

}

int partitionNutsNBolts(vector<int>& container, int low, int high, int pivot_value)
{

    int lastEndIndex = low - 1;

    for(int currIndex = low; currIndex < high; currIndex++)
    {
        int value = container[currIndex];
        if( value < pivot_value )
        {
            lastEndIndex++;
            int temp = container[currIndex];
            container[currIndex] = container[lastEndIndex];
            container[lastEndIndex] = temp;


        }
        if( value == pivot_value )
        {
            int temp = container[currIndex];
            container[currIndex] = container[high];
            container[high] = temp;
            currIndex--;
        }
    }

    lastEndIndex++;
    int temp = container[high];
    container[high] = container[lastEndIndex];
    container[lastEndIndex] = temp;

    return lastEndIndex;
}


vector<pair<pci,pci>> nutsNBoltsUtil(vector<int>& nuts, vector<int>& bolts, int low, int high)
{
    vector<pair<pci,pci>> res;
    if(high <= low)
        return res;

    DEBUG_DEBUG(cout << " Partitioning Bolts \n");
    int pivot_value = nuts[high];
    int pivot_loc = partitionNutsNBolts(bolts, low, high, pivot_value);
    printNutsNBolts(nuts, bolts);


    DEBUG_DEBUG(cout << " Partitioning Nuts \n");
    pivot_value = bolts[pivot_loc];
    pivot_loc = partitionNutsNBolts(nuts,low, high, pivot_value);
    printNutsNBolts(nuts, bolts);

    nutsNBoltsUtil(nuts, bolts, low, pivot_loc - 1);
    nutsNBoltsUtil(nuts, bolts, pivot_loc + 1, high);

    return res;
}

/*
 * Problem:
 * Given a set of n nuts of different sizes and n bolts of different sizes. There is a one-one mapping between nuts and bolts.
 * Match nuts and bolts efficiently. Constraint: Comparison of a nut to another nut or a bolt to another bolt is not allowed.
 * It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.
 * Other way of asking this problem is, given a box with locks and keys where one lock can be opened by one key in the box.
 * We need to match the pair.
 *
 * Approach: Very tricky problem.
 * You take a nut and place all bolts smaller than the corresponding bolt to the left and larger to the right.
 * Now, you take the pivot returned by the previous partitioning and partition all nuts.
 * Repeat the above process for all elements to the right and left of the partition.
 *
 * Also look at the partitioning scheme very carefully. Lomuto partition scheme is used. One thing that we do different here is
 * when we come across bolt for a nut, we place the bolt at the end and implicitly make it the pivot. so, after the loop pivot is at the end
 * and all other items are partitioned properly. Now you can go ahead and place the pivot at the exact location it belongs to.
 *
 * Complexity:
 * Space Complexity:
 *
 */

vector<pair<pci,pci>> IKSolution::nutsNBolts(vector<pci>& nuts, vector<pci>& bolts)
{
    vector<int> nutsa;
    vector<int> boltsa;
    vector<pair<pci,pci>> res;

    for(auto it : nuts)
    {
        nutsa.push_back(it.second);
    }

    for(auto it : bolts)
    {
        boltsa.push_back(it.second);

    }

    printNutsNBolts(nutsa, boltsa);

    nutsNBoltsUtil(nutsa, boltsa,0, nuts.size() - 1);

    for(int i = 0; i < nutsa.size(); i++)
    {
        res.push_back(make_pair( make_pair('N', nutsa[i]), make_pair('B', boltsa[i])));
    }

    return res;
}

/***********************************************************************************************/

vector<int> mergeSortedArrays(vector<int> a, vector<int> b)
{
    vector<int> res;
    int index1 = 0;
    int index2 = 0;
    int resIndex = 0;

    while(index1 < a.size() && index2 < b.size())
    {
        if(a[index1] < b[index2])
        {
            res.push_back(a[index1]);
            index1++;
        }
        else
        {
            res.push_back(b[index2]);
            index2++;
        }
    }
    while(index1 < a.size())
    {
        res.push_back(a[index1]);
        index1++;
    }

    while(index2 < b.size())
    {
        res.push_back(b[index2]);
        index2++;

    }
    return res;
}

/*
 * Problem:
 *     Given k sorted arrays of size n each, merge them and print the sorted output.
 * Approach:
 *
 * Complexity: nk(lognk)
 * Space Complexity:
 * Optimization:
 *     Implement your own priority queue instead of using the STL.
 *
 *     We can merge arrays in O(nk*Logk) time using Min Heap. Following is detailed algorithm.
       1. Create an output array of size n*k.
       2. Create a min heap of size k and insert 1st element in all the arrays into a the heap
       3. Repeat following steps n*k times.
          a) Get minimum element from heap (minimum is always at root) and store it in output array.
          b) Replace heap root with next element from the array from which the element is extracted.
          If the array doesn’t have any more elements, then replace root with infinite.
          After replacing the root, heapify the tree.
 *
 */

vector<int> IKSolution::mergearrays(vector<vector<int>> iarray)
{
    vector<int> arr3;
    int K = iarray.size();
    int n = iarray[0].size();

#if 0
    vector<int> arr1 = iarray[0];
    vector<int> arr2;


    for(int i = 1; i < K; i++)
    {
        arr2 = iarray[i];
        arr3 = mergeSortedArrays(arr1, arr2);
        arr1 = arr3;
    }
#endif

    priority_queue<int,vector<int>,greater<int> > q;
    for(int i = 0; i < (K); i++)
    {
        for(int j = 0; j < (n); j++)
        {
            q.push(iarray[i][j]);
        }
    }
    DEBUG_DEBUG(cout << "Min-heap, popped one by one: ");

    while(!q.empty() )
    {
        cout << q.top() << ' ';
        arr3.push_back(q.top());
        q.pop();
    }
    DEBUG_DEBUG(cout << " \n");

    return arr3;
}
/******************************************************************************************************/

/*
 * Problem:
 *     k largest(or smallest) elements in an array
 *
 * Approach:
 *     1) Build a Min Heap MH of the first k elements (arr[0] to arr[k-1]) of the given array. O(k)
       2) For each element, after the kth element (arr[k] to arr[n-1]), compare it with root of MH.
          ……a) If the element is greater than the root then make it root and call heapify for MH
          ……b) Else ignore it.
          // The step 2 is O((n-k)*logk)

       3) Finally, MH has k largest elements and root of the MH is the kth largest element.

       Time Complexity: O(k + (n-k)Logk) without sorted output. If sorted output is needed then O(k + (n-k)Logk + kLogk)
 *
 * Complexity:
 * Space Complexity:
 * Optimization:
 *
 */

vector<int> IKSolution::twitterTopK(vector<int>iStream, int iK)
{
    priority_queue<int,vector<int>,greater<int> > q;
    vector<int> res;

    for(int i = 0; (i < iK) && (i < iStream.size()) ; i++)
    {
        q.push(iStream[i]);
    }

    for(int i = iK; i < iStream.size(); i++)
    {
        if(iStream[i] > q.top())
        {
            q.pop();
            q.push(iStream[i]);
        }
    }

    int size = q.size();
    for(int i = 0; i < size; i++)
    {
        res.push_back(q.top());
        q.pop();

    }
    return res;


}





/*
 * Problem:
 *     Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 *     Find all unique triplets in the array which gives the sum of zero.
 *
 * Approach:
 *      Sort the array.
 *      Have three pointers.
 *      Pointer A: One starting from Left and goes right.
 *      Pointer B: Starting Pointer A - 1 and going right
 *      Pointer C: Starting from end and going left.
 *      When the sum of all three is equal to zero, print
 *      When the sum of all three is greater than zero then we move the pointer C to left(reduce the sum)
 *      When the sum of all three is less than zero then we move the pointer B to right(increase the sum)

 * Complexity:
 *     O(n*n)
 *
 * Space Complexity:
 * Optimization:
 * Take Away:
 *      Different ways of asking the problem:
 *      http://www.geeksforgeeks.org/find-number-of-triangles-possible/
 *      Given an unsorted array of positive integers. Find the number of triangles that can be formed with three
 *      different array elements as three sides of triangles. For a triangle to be possible from 3 values, the sum of
 *      any two values (or sides) must be greater than the third value (or third side).
        For example, if the input array is {4, 6, 3, 7}, the output should be 3.
        There are three triangles possible {3, 4, 6}, {4, 6, 7} and {3, 6, 7}. Note that {3, 4, 7} is not a possible triangle.
 *
 */
vector<string> IKSolution::printTriplets(vector<int> intArr)
{
    IKSolution soln;
    vector<string> res;

    vector<int> sortArr = soln.quickSort(intArr);

    DEBUG_DEBUG(cout << "After sorting the values are: ");
    for(int i = 0; i < sortArr.size(); i++)
    {
        DEBUG_DEBUG(cout << sortArr[i] << " ");
    }
    DEBUG_DEBUG(cout << " \n");

    if(sortArr.size() == 3)
    {
        if(sortArr[0] + sortArr[1] + sortArr[2] == 0 )
        {
            string s = to_string(sortArr[0]) + "," + to_string(sortArr[1]) + "," +  to_string(sortArr[2]);
            res.push_back(s);
        }
    }

    for(int i = 0; i < (sortArr.size() - 3); i++)
    {
        int j = (i + 1);
        int k = sortArr.size() - 1;

        if((i == 0) || (sortArr[i] > sortArr[i-1])) //Handle duplicates
        {
            while(j < k)
            {
                if((sortArr[i] + sortArr[j] + sortArr[k]) == 0)
                {
                   DEBUG_DEBUG(cout << "SUM Zero Found: " << sortArr[i] << " " << sortArr[j] << " " << sortArr[k] );
                   DEBUG_DEBUG(cout << " \n");
                   string s = to_string(sortArr[i]) + "," + to_string(sortArr[j]) + "," +  to_string(sortArr[k]);
                   res.push_back(s);

                   j++;
                   k--;

                   //handle duplicate here
                   while(j<k && sortArr[j]== sortArr[j-1])
                       j++;
                   while(j<k && sortArr[k]== sortArr[k+1])
                       k--;

                }
                else if((sortArr[i] + sortArr[j] + sortArr[k]) > 0)
                {
                    k = k - 1;
                }
                else
                {
                    j = j + 1;
                }

            }
        }
    }

    return res;
}



/*******************************************************************************************************************************/
#if 0

//Find the closest pair from two sorted arrays
//Given two sorted arrays and a number x, find the pair whose sum is closest to x and the
//pair has an element from each array.


findTheRankOfTheElement(aray a, int k)
{
    for(int i = 0)
    {

    }

    index = i;
    val = a[index];

    for(i = 0; i < size; i++)
    {

       if(a[i] < val)
       {
          swap(a[i], a[index]);
          i++;
       }
       else
       {
          swap(a[size-1],a[index]);
       }

    }




}

/* Build the pivot logic*/
int functionToPlace(vector<int> a)
{
    index = 0;
    val = a[index];

    for(i = 0; i < size; i++)
    {

         if(a[i] < val)
         {
             swap(a[i], a[index]);
             i++;
         }
         else
         {
             swap(a[size-1],a[index]);
         }

    }
}




#endif



