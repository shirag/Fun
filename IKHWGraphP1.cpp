/*
 * IKHWGraphP1.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: Raghav Navada
 */


#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include "IKMurmur.h"

#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"


/************************************************************************************************/
int printAllPathsInAGraphUtil(vvi& g, vector<int>& v, int &src, int& dest, vvi& paths)
{
    int size =  g.size();
    if(src >= size)
        return 0;
    //cout << "next src " << src << "\n";

    for(auto val : v)
        if(val == src)
            return 0;

    v.push_back(src);
    if(src == dest)
    {
        paths.push_back(v);
        v.erase(v.end()-1);
        return 1;
    }

    for(auto val : g[src])
        printAllPathsInAGraphUtil(g, v, val, dest, paths);

    v.erase(v.end()-1);

    return 0;
}


/* Problem: Print all paths.
 * Example:
 * Approach: Push the node to a vector. Do a pre-order DFS search. Erase after processing children.
 * Complexity:
 * Space Complexity:
 * Any other better approach:
 * Corner case:
 * Take away:
 */
int IKSolution::printAllPathsInAGraph(vvi& g, int src, int dest)
{
    cout << "no of vertex = " << g.size() << "\n";

    vector<int> v;
    vvi paths;

    printAllPathsInAGraphUtil(g, v, src, dest, paths);

    for(unsigned int i = 0; i < paths.size(); i++)
    {
        cout << "\n size of path " << i << ":"  << paths[i].size() << " Elements: ";
        for(auto val : paths[i])
        {
            cout << " " << val << " ";
        }
    }

    cout << "\n";
    return 0;
}




vvi printAllPathsInAGraphUtilAlter(vvi& g, vector<int>& v, int &src, int& dest)
{
    vvi paths;

    int size =  g.size();
    if(src >= size)
        return paths;


    for(auto val : v)
        if(val == src)
            return paths;

    v.push_back(src);
    if(src == dest)
    {
        paths.push_back(v);
        v.erase(v.end()-1);
        return paths;
    }

    for(auto val : g[src])
    {
        vvi temp = printAllPathsInAGraphUtilAlter(g, v, val, dest);
        paths.insert(paths.end(),temp.begin(), temp.end());
    }

    v.erase(v.end()-1);

    return paths;
}


/* Problem: Print all paths(Alternate approach. Recursively copy).
 * Example:
 * Approach: Push the node to a vector. Do a pre-order DFS search. Erase after processing children.
 * Complexity:
 * Space Complexity:
 * Any other better approach:
 * Corner case:
 * Take away:
 */
vvi IKSolution::printAllPathsInAGraphAlter(vvi& g, int src, int dest)
{
    cout << "no of vertex = " << g.size() << "\n";
    vector<int> v;
    return printAllPathsInAGraphUtilAlter(g, v, src, dest);
}


/************************************************************************************************/


int countComponentsUtil(vvi & W, int node, vector<bool>& flag)
{

    if(node >= W.size())
        return 0;

    cout << "processing node " << node << "\n";


    for(vector<int>::iterator it = W[node].begin(); it != W[node].end(); it++)
    {
        if(flag[*it] == 0)
        {
            flag[*it] = 1;
            countComponentsUtil(W,*it,flag);
        }
    }

    return 0;

}



/* Problem: Count the number of connected components
 * Example:
 * Approach: DFS search. After every main loop if any vertex is not visited, then do a DFS traversal again.
 * Complexity:
 * Space Complexity:
 * Any other better approach:
 * Corner case:
 * Take away:
 */
int countComponents(int n, vector< pair<int, int> >& edges)
{
    vector< vector<int> > W(n);//graph representation
    vector<bool> flag(n,0);
    int counter = 0;
    int j = 0;

    if(n > 0)
        counter = 1;

    /* Generate graph data structure using edges */
    for(vector< pair<int, int> >::iterator it = edges.begin(); it != edges.end(); it++)
    {
        W[it->first].push_back(it->second);
        W[it->second].push_back(it->first);
    }

    for(int i = 0; i < n; i++)
    {
        if(flag[i] == 0)
        {
            flag[i] = 1;
            countComponentsUtil(W,i,flag);
            counter++;
        }
    }

    return counter;
}

/******************************************************************************************************/
int getNextLocation(int rows, int columns, int startx, int starty, lpii& lt)
{

    int nx = startx + 1;
    int ny = starty + 2;


    if((nx < columns) && (ny < rows))
        lt.push_back(make_pair(nx,ny));

    nx = startx + 2;
    ny = starty + 1;

    if((nx < columns) && (ny < rows))
        lt.push_back(make_pair(nx,ny));

   nx = startx - 1;
   ny = starty - 2;

   cout << "\n" << " nx  = "  << nx ;
   cout << " ny  = "  << ny ;

   if((nx >= 0) && (ny >= 0))
       lt.push_back(make_pair(nx,ny));

   nx = startx - 2;
   ny = starty - 1;

   cout << "\n" << " nx  = "  << nx ;
   cout << " ny  = "  << ny << "\n" ;


   if((nx >= 0) && (ny >= 0))
       lt.push_back(make_pair(nx,ny));

   nx = startx - 1;
   ny = starty + 2;

   cout << "\n" << " nx  = "  << nx ;
   cout << " ny  = "  << ny ;

   if((nx >= 0) && (ny >= 0))
       lt.push_back(make_pair(nx,ny));

   nx = startx - 2;
   ny = starty + 1;

   cout << "\n" << " nx  = "  << nx ;
   cout << " ny  = "  << ny ;

   if((nx >= 0) && (ny >= 0))
       lt.push_back(make_pair(nx,ny));

   nx = startx + 2;
   ny = starty - 1;

   cout << "\n" << " nx  = "  << nx ;
   cout << " ny  = "  << ny ;

   if((nx >= 0) && (ny >= 0))
       lt.push_back(make_pair(nx,ny));

   nx = startx + 1;
   ny = starty - 2;

   cout << "\n" << " nx  = "  << nx ;
   cout << " ny  = "  << ny ;

   if((nx >= 0) && (ny >= 0))
       lt.push_back(make_pair(nx,ny));

    return 1;
}

/* Problem:
 *       Knight's Shortest Path Chess Question.
 *       You are given starting and ending location in terms of x and y axis.
 *       Goal is to calculate the shortest number of moves that the knight can take to get to the
 *       target location.
 *
 * Example:
 * Approach:
 *       BFS search over all the neighbors. Have a utility function to get neighbors. When you hit the
 *       destination just print the level and come out.
 *       Basically derive a function that defines the edge between graphs(Nelson golden rule).
 *       Push to the MAIN queue a list of all  dest x,y's at a particular level. So, when you pop out from the list,
 *       you are popping out all x, and ys at a particular level.
 * Complexity:
 * Space Complexity:
 * Any other better approach:
 * Corner case:
 * Take away:
 */
int IKSolution::knightsTourOnChessBoard(int rows, int columns, int sx, int sy, int ex, int ey)
{
    unsigned int level = 0;
    lpii lpop;  //List used to push
    lpii lpush; //List used to pop
    qlpii qm;   //Main processing queue. Above two lists are pushed and popped
    spii flags; //Set of visited flag

    pii end = make_pair(ex,ey); //Destination

    lpush.push_back(make_pair(sx, sy));
    qm.push(lpush);
    lpush.clear();
    //flags.insert(make_pair(sx, sy));


    while(!qm.empty())
    {
        lpop = qm.front();
        qm.pop();

        for(auto val : lpop)
        {
            if(flags.find(val) != flags.end())
                continue;

            if(val == end)
            {
                DEBUG_DEBUG(cout<< " We found the destination at level = " << level << "\n");
                return level;
            }

            flags.insert(val);
            getNextLocation(rows, columns, val.first, val.second, lpush);
        }

        if(!lpush.empty()) // important check
        {
            qm.push(lpush);
            lpush.clear();
        }

        level++;
    }

    return level;

}

/*************************************************************************************************************************/
bool oneDiff(string& s1, string& s2)
{

    int size1 = s1.size();
    int size2 = s2.size();
    int index = 0;
    bool ondiffFound = false;

    if(s1 == s2)
        return 0;

    while((index < size1) && (index < size2))
    {
        if( (s1[index] != s2[index]) && (ondiffFound == false))
            ondiffFound = true;
        else if( (s1[index] != s2[index]) && ondiffFound == true)
            return 0;

        index++;
    }

    return 1;
}


int getNextLevelStrings(ls& dict, string& begin, ls& l, map<string,string>& mp)
{

    for(ls::iterator it = dict.begin(); it != dict.end() ; it++)
    {
        if(oneDiff(begin,*it) == 1)
        {
            l.push_back(*it);
            if(mp.find(*it) == mp.end())
            {
                mp[*it] = begin;
            }
        }
    }

    return 0;
}



/* Problem:
           Convert string a to b using a dictionary of words. Each hop can have only one difference of character.
 * Example:
 *         dictionary: {"cat", "bat", "hat", "bad", "had"}
           a = "bat"
           b = "had"
           solution:
           "bat" -> "bad" -> "had"
 * Approach:
 *         Graph BFS search. Build the graph as your traverse. For every node visited store the
 *         src node in a map. When you hit the destination come out of the search.
 *         Populate contents of the map onto a stack and then print contents of the stack.
 *
 * Complexity: n * n * m(where n is the no of strings and m is chars in each string)
 * Space Complexity: O(1)
 * Any other better approach:
 *         For finding the difference you can use a map instead of going over the loop.
 *         By doing that you will use n*n*m space and then n time and n*n*m space.
 * Corner case:
 * Take away:
 *        Identify the connection function.
 */
vector<string> IKSolution::convertAString(ls& dict, string& begin, string& end)
{
    unsigned int level = 0;

    ls lpop;  //List used to push
    ls lpush; //List used to pop
    qls qm;   //Main processing queue. Above two lists are pushed and popped
    ss flags; //Set of visited flag
    map<string,string> mp;

    lpush.push_back(begin);
    qm.push(lpush);
    lpush.clear();

    mp[begin] = "";

    while(!qm.empty())
    {
        lpop = qm.front();
        qm.pop();


        for(auto val : lpop)
        {
            if(flags.count(val))
                continue;

            if(val == end)
            {
                DEBUG_DEBUG(cout << "line# "<< __LINE__<< ": "; cout<< " We found the destination at level = " << level << "\n");
                break;
            }

            flags.insert(val);
            getNextLevelStrings(dict, val, lpush, mp);

        }
        if(!lpush.empty()) // important check
        {
            qm.push(lpush);
            lpush.clear();
        }

        level++;
    }

    vector<string> ret;

    string temp = end;
    while(mp.count(temp))
    {
        ret.push_back(temp);
        temp = mp[temp];
    }

    ret = vector<string>(ret.rbegin(), ret.rend());

    return ret;
}
/*******************************************************************************************************/
struct topNode
{
    char val;
    unsigned int index;
};
typedef list<topNode> lnp;

/* Node used to topological sort */
int topologicalSortUtilDFS(vector<lnp>& g, int i, set<char>& visited, stack<char>& s)
{
    topNode tn = g[i].front();
    visited.insert(tn.val);

    DEBUG_TRACE(cout << "processing node val " << tn.val << "\n");

    for(auto it = (++(g[i].begin())); it != g[i].end(); it++)
    {
        cout << "it->val =  " << it->val << "\n";
        cout << "it->index =  " << it->index << "\n";

        auto it1 = visited.find(it->val);
        if(it1 == visited.end())
        {
            topologicalSortUtilDFS(g, it->index, visited, s);
        }
    }
    cout << "pushing " << tn.val << "\n" ;
    s.push(tn.val);

    return 0;
}


int addEdges(vector<string>& words, int n, int alpha, vector<lnp>& g)
{
    // Process all adjacent pairs of words and create a graph
    for (int i = 0; i < n-1; i++)
    {
        // Take the current two words and find the first mismatching
        // character. Populate the graph and then break out of loop.
        string word1 = words[i], word2 = words[i+1];

        for (int j = 0; j < min(word1.size(), word2.size()); j++)
        {
            // If we find a mismatching character, then add an edge
            // from character of word1 to that of word2
            if(word1[j] != word2[j])
            {
                cout << " adding an edge between " << word1[j] << " and " << word2[j] << "\n" ;
                if(!(g[word1[j]-'a'].size()))
                {
                    //cout << " init \n";
                    topNode tn; tn.val = word1[j]; tn.index = word1[j]-'a';
                    cout << "g[" << word1[j]-'a' << "]" << " = " <<  tn.val << " index = " << word1[j]-'a' << "\n" ;
                    g[word1[j]-'a'].push_back(tn);
                }

                if(!(g[word2[j]-'a'].size()))
                {
                    //cout << " init \n";
                    topNode tn; tn.val = word2[j]; tn.index = word2[j]-'a';
                    cout << "g[" << word2[j]-'a' << "]" << " = " <<  tn.val << " index = " << word2[j]-'a' << "\n" ;
                    g[word2[j]-'a'].push_back(tn);
                }

                topNode tn; tn.val = word2[j]; tn.index = word2[j]-'a';
                g[word1[j]-'a'].push_back(tn);
                cout << "g[" << word1[j]-'a' << "]"<< " = " << tn.val << " index = " << word2[j]-'a' << "\n" ;

                //return 0;
                break;
            }
        }
    }

    return 0;
}

/* Problem: Topological sort. Given a sorted dictionary (array of words) of an alien language, find order of characters in the language.
 *          Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every
 *          directed edge uv, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
 *
 *          Topological sort is something similar to DFS.
 *
 * Example:
 *          Input:  words[] = {"baa", "abcd", "abca", "cab", "cad"}
            Output: Order of characters is 'b', 'd', 'a', 'c'
            Note that words are sorted and in the given language "baa"
            comes before "abcd", therefore 'b' is before 'a' in output.
            Similarly we can find other orders.

            Input:  words[] = {"caa", "aaa", "aab"}
            Output: Order of characters is 'c', 'a', 'b'
 * Approach:
 *          Generate the graph using input words. Compare each word with the next one.
 *          When you found a different char, build a graph vertex and connect corresponding edges.
 *          Now you have a graph of all characters with directed edges.
            Once the graph is generated, do a DFS search and while doing the search push leaf to a stack.
            Print content of the stack.

            1) Create a graph g with number of vertices equal to the size of alphabet in the given alien language.
              For example, if the alphabet size is 5, then there can be 5 characters in words. Initially there are no edges in graph.
            2) Do following for every pair of adjacent words in given sorted array.
              …..a) Let the current pair of words be word1 and word2. One by one compare characters of both words and find the first mismatching characters.
              …..b) Create an edge in g from mismatching character of word1 to that of word2.
            3) Print topological sorting of the above created graph.
 *
 * Complexity:
 * Space Complexity:
 * Any other better approach:
 *
 * Corner case:
 * Take away:
 *        Identify the connection function.
 */
string IKSolution::topologicalSort(vector<string> strDict) //m is the no of strings and n is the no of chars in string.
{

    vector<char> rs;
    int m = strDict.size();
    int n = strDict[0].size();

    unsigned int mxChars = 0;
    cout << "m = " << m;
    cout << "n = " << n;

    for(auto it = strDict.begin(); it != strDict.end(); it++ )
    {
        unsigned int size = it->size();
        mxChars += size;
    }

    vector<lnp> W(mxChars); //graph representation, vector of lists.Each node in the list represents a character.
    addEdges(strDict, m, mxChars, W);

    int i = 0;
    stack<char> s1;
    set<char> visited;

    for(i = 0; i < mxChars; i++)
    {
        if(!W[i].empty())
        {
            topNode tn = W[i].front();
            if(visited.find(tn.val) == visited.end())
                topologicalSortUtilDFS(W, i, visited, s1);
        }
    }

    string rss;
    while(!s1.empty())
    {
        cout << " " << s1.top();
        rss.push_back(s1.top());
        s1.pop();
    }

    cout << "sorted order = " << rss;

    return rss;

}

/************************************************************************************************************/


int getAllNeighbors(vvi& matrix, int row , int column, lpii& n, int maxRows, int maxColumns)
{

    if( ((row + 1) < maxRows) && ((column + 1) < maxColumns) )
    {
        if( (matrix[row][column] == 1) && (matrix[row + 1][column + 1]) )
        {
            n.push_back(make_pair(row,column));
        }
    }

    if( ((row - 1) >= 0) && ((column - 1) >= 0) )
    {
        if( (matrix[row][column] == 1) && (matrix[row - 1][column - 1]) )
        {
            n.push_back(make_pair(row - 1, column - 1));
        }
    }

    /**********************************************************/

    if( ((column + 1) < maxColumns) )
    {
        if( (matrix[row][column] == 1) && (matrix[row][column + 1]) )
        {
            n.push_back(make_pair(row, column + 1));
        }
    }

    if( ((column - 1) >= 0) )
    {
        if( (matrix[row][column] == 1) && (matrix[row][column - 1]) )
        {
            n.push_back(make_pair(row, column - 1));
        }
    }
    /**********************************************************/


    if( ((row + 1) < maxRows)  )
    {
        if( (matrix[row][column] == 1) && (matrix[row + 1][column]) )
        {
            n.push_back(make_pair(row + 1, column));
        }
    }

    if( ((row - 1) >= 0) )
    {
        if( (matrix[row][column] == 1) && (matrix[row - 1][column]) )
        {
            n.push_back(make_pair(row - 1, column));
        }
    }

    /**********************************************************/


    if( ((row - 1) >= 0) && ((column + 1) < maxColumns)  )
    {
        if( (matrix[row][column] == 1) && (matrix[row - 1][column + 1]) )
        {
            n.push_back(make_pair(row - 1, column + 1));
        }
    }

    if( ((row + 1) < maxRows) && (column - 1 >= 0) )
    {
        if( (matrix[row][column] == 1) && (matrix[row + 1 ][column - 1]) )
        {
            n.push_back(make_pair(row + 1, column - 1));
        }
    }


    return 0;

}
/***************************************************************************************************************/

int countNoOfIslandsUtil(vvi matrix, set<pair<int,int>>& flags, int row, int column, int maxRows, int maxColumns)
{
    lpii n;
    cout << "processing row " << row <<  "column "<<  column << "\n";

    flags.insert(make_pair(row,column));

    getAllNeighbors(matrix, row, column, n, maxRows, maxColumns);

    for(auto it = n.begin(); it != n.end(); it++)
    {
        auto itF = flags.find(*it);
        if(itF == flags.end())
        {
            countNoOfIslandsUtil(matrix, flags,it->first,it->second, maxRows, maxColumns);
        }
    }

    return 0;
}

/* Problem:
 *     Find the number of islands
 * Example:
 *     Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms an island. For example, the below matrix contains 5 islands

       Input : mat[][] =  {{1, 1, 0, 0, 0},
                          {0, 1, 0, 0, 1},
                          {1, 0, 0, 1, 1},
                          {0, 0, 0, 0, 0},
                          {1, 0, 1, 0, 1}
       Output : 5
 *
 * Approach: Go over each element of the matrix and perform a DFS if its one and not already searched.
 *            When you come out of DFS, you might have visited one complete component.
 *
             Solved by applying DFS() on each component. In each DFS() call,
 *           a component or a sub-graph is visited. We will call DFS on the next un-visited component.
 *           The number of calls to DFS() gives the number of connected components. BFS can also be used.
 * Time Complexity: O(row * column)
 * Space Complexity:
 * Any other better approach:
 * Corner case:
 * Take away:
 */
int IKSolution::countNoOfIslands(vvi matrix)
{
    int rows;
    int columns;
    int index = 0;

    set<pair<int,int>> flags;
    int counter = 0;

    rows = matrix.size();
    columns = matrix[0].size();

    cout << "rows = " << rows;
    cout << "columns = " << columns << "\n";

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            auto it = flags.find(make_pair(i,j));
            if( (matrix[i][j]) && (it == flags.end()) )
            {
                countNoOfIslandsUtil(matrix, flags, i, j, rows, columns);
                counter++;
            }
        }
    }

    return counter;
}

/*****************************************************************************************************/
/* http://www.maxburstein.com/blog/creating-a-simple-bloom-filter/ */
/* http://blog.michaelschmatz.com/2016/04/11/how-to-write-a-bloom-filter-cpp/ */
/* Imagine black boxes with multiple labels indicating what can be stored inside them. e.g. In one box you
 * would store shoe/jacket. In another one you would store jacket/sweater etc. When somebody asks if I have an
 * item, the way I would answer is by weighing the corresponding box, and depending on the weight I say "NO" or "MAY BE".
 * So, if all corresponding boxes are empty then I know for sure that item is not present. But if one of the
 * boxes is non empty then I come back and say that item is present. I might be totally wrong in here. But, its OK.
 * I saved space by storing multiple items in one box.
 *
 * Assignement is to create a bloom filter of dictionary, and then words. Look up for words. Compare times
 * against linear search and hash-table.
 */
array<uint64_t, 2> hashF(const uint8_t *data, size_t len)
{
    array<uint64_t, 2> hashValue;
    MurmurHash3_x64_128(data, len, 0, hashValue.data());
    return hashValue;
}

inline uint64_t nthHash(uint8_t n,
                        uint64_t hashA,
                        uint64_t hashB,
                        uint64_t filterSize)
{
    return (hashA + n * hashB) % filterSize;
}



void BloomFilter::add(const uint8_t *data, std::size_t len)
{
    array<uint64_t, 2> hashValues = hashF(data, len);

    for (int n = 0; n < m_numHashes; n++)
    {
        m_bits[nthHash(n, hashValues[0], hashValues[1], m_bits.size())] = true;
    }
}

bool BloomFilter::possiblyContains(const uint8_t *data, std::size_t len) const
{
    array<uint64_t, 2>  hashValues = hashF(data, len);

    for (int n = 0; n < m_numHashes; n++)
    {
        if (!m_bits[nthHash(n, hashValues[0], hashValues[1], m_bits.size())])
        {
            DEBUG_DEBUG(cout << "line# "<< __LINE__<< " returning false \n");
            return false;
        }
    }

    DEBUG_DEBUG(cout << "line# "<< __LINE__<< " returning true \n");
    return true;
}
/*****************************************************************************************************/
/*
 * Problem:
 *     Given a snake and ladder board, find the minimum number of dice throws required to reach the destination
 *     or last cell from source or 1st cell. Basically, the player has total control over outcome of dice throw
 *     and wants to find out minimum number of throws required to reach last cell.
 *     If the player reaches a cell which is base of a ladder, the player has to climb up that ladder and if
 *     reaches a cell is mouth of the snake, has to go down to the tail of snake without a dice throw.
 * Approach:
 * Time Complexity:
 *
 * Alternate approach:
 *
*/
void giveMeAllLocations(int currentCell, list<int>& dest, unordered_map<int,int>& locations, int totalLocations,  set<int>& vis)
{
    unordered_map<int,int> ladders;
    unordered_map<int,int> snakes;

    for(int i = 1; i <= 6; i++)
    {

        if(locations.count(currentCell + i))
        {
            if(!vis.count(locations[currentCell + i]))
            {
                dest.push_back(locations[currentCell + i]);
                vis.insert(locations[currentCell + i]);
            }

        }
        else
        {
            if(currentCell + i <= totalLocations)
                if(!vis.count(currentCell + i))
                {
                    dest.push_back(currentCell + i);
                    vis.insert(currentCell + i);
                }
        }
    }
}


void populatePrev(int prev, list<int>pushl, map<int,int>& prevMap)
{
    for(auto val : pushl)
    {
        if(prevMap.count(val) == 0)
            prevMap[val] = prev;
    }
}

int IKSolution::snakeNLadder(int m, int n, unordered_map<int,int> locations, map<int,int>& prevMap)
{
    queue<list<int>> mQ;
    list<int> popl;
    list<int> pushl;
    int level = 0;
    int finalLoc = m * n;
    set<int> vis;

    pushl.push_back(1);
    mQ.push(pushl);
    pushl.clear();
    vis.insert(1);

    while(!mQ.empty())
    {
        popl = mQ.front();
        mQ.pop();

        for(auto val : popl)
        {
            if(val == finalLoc)
                return level;

            giveMeAllLocations(val, pushl, locations, finalLoc, vis);
            populatePrev(val, pushl, prevMap);
        }
        mQ.push(pushl);
        pushl.clear();
        level++;
    }

    return 0;
}
/**********************************************************************************************************************/
class CompareDist1
{
    public:
        bool operator()(pair<int,int> n1,pair<int,int> n2)
        {
            return n1.second > n2.second;
        }
};


int getValueFromIndex(vvi ip, int index)
{
    int columns = ip[0].size();
    int rows = ip.size();

    assert( (index >= 0) && index < (rows * columns));

    int row = index/columns;
    int column = index % columns;

    return ip[row][column];
}


int getMin(vvi ip, int index)
{
    priority_queue<pii, vector<pii>, CompareDist1> q;
    int leftOffSet = index % ip[0].size();
    int elements = ip[0].size() * ip.size();
    int columns = ip[0].size();

    q.push({index, getValueFromIndex(ip, index)});

    if((leftOffSet - 1) >= 0 )
        q.push({index - 1, getValueFromIndex(ip, index - 1)});

    if((leftOffSet + 1) < columns)
        q.push({index + 1, getValueFromIndex(ip, index + 1)});

    if(index - columns >= 0)
        q.push({(index - columns), getValueFromIndex(ip, index - columns)} );

    if(index + columns < elements)
        q.push({(index + columns), getValueFromIndex(ip, index + columns)} );

    int top = q.top().first;

    return top;
}


int getTheSink(vvi ip, map<int, int>& sinks, int myIndex)
{
    int sinkVal;

    int lowIndex = getMin(ip, myIndex);
    if(lowIndex == myIndex) //If i'm the lowest val compared to all my neighbors, make me the sink
    {
        sinks[myIndex] = myIndex;
        return myIndex;
    }

    if(sinks.count(lowIndex)) //if the lowest neighbor has a sink, then
    {
        sinks[myIndex] = sinks[lowIndex];
        return sinks[lowIndex];
    }

    sinkVal = getTheSink(ip, sinks, lowIndex);
    sinks[myIndex] = sinks[sinkVal];

    return sinkVal;
}

bool myfunction(pair<int,int> p1, pair<int, int> p2)
{
    return (p1.second < p2.second);
}


/* Problem:
 *     A group of farmers has some elevation data, and we're going to help them understand how rainfall flows over their farmland.
       We'll represent the land as a two-dimensional array of altitudes and use the following model, based on the idea that water flows downhill:
       If a cell’s four neighboring cells all have higher altitudes, we call this cell a sink; water collects in sinks.
       Otherwise, water will flow to the neighboring cell with the lowest altitude. If a cell is not a sink, you may assume it has a
       unique lowest neighbor and that this neighbor will be lower than the cell.
       Cells that drain into the same sink – directly or indirectly – are said to be part of the same basin.

       Your challenge is to partition the map into basins. In particular, given a map of elevations, your code should partition the map
       into basins and output the sizes of the basins, in descending order.
       Assume the elevation maps are square. Input will begin with a line with one integer, S, the height (and width) of the map.
       The next S lines will each contain a row of the map, each with S integers – the elevations of the S cells in the row.
       Some farmers have small land plots such as the examples below, while some have larger plots. However, in no case will a farmer
       have a plot of land larger than S = 5000.

       Your code should output a space-separated list of the basin sizes, in descending order. (Trailing spaces are ignored.)

   Approach:

       The interviewer might certainly looking for one answer: "union-find data structure" or "disjoint sets data structure".

       Go over each and every element of the input array. For each cell recursively calculate the sink. Store the result in a map(cellno, sink)
       go over the map again to count the no of occurance. Return the result in a heap.
       As you pop the contents of the heap, you will get the result in descending order.

   Complexity:
       Its O(n)

   Example:

          -----------------------------------------
          Input:                 Output:
             3                      7 2
          1 5 2
          2 4 7
          3 6 9

          The basins, labeled with A’s and B’s, are:
          A A B
          A A B
          A A A
          -----------------------------------------
          Input:                  Output:
             1
            10

          There is only one basin in this case.
          The basin, labeled with A’s is:
             A
          -----------------------------------------
          Input:                  Output:
             5                    11 7 7
         1 0 2 5 8
         2 3 4 7 9
         3 5 7 8 9
         1 2 5 4 3
         3 3 5 2 1

         The basins, labeled with A’s, B’s, and C’s, are:
         A A A A A
         A A A A A
         B B A C C
         B B B C C
         B B C C C
         -----------------------------------------
          Input:                  Output:
            4                       7 5 4
         0 2 1 3
         2 1 0 4
         3 3 3 3
         5 5 2 1

         The basins, labeled with A’s, B’s, and C’s, are:
         A A B B
         A B B B
         A B B C
         A C C C
         -----------------------------------------
 *
 * */


priority_queue<int> IKSolution::detectBasins(vvi ip)
{
    map<int, int> res;
    unordered_map<int, int> retVal;
    int index = 0;
    priority_queue<int> pq;
    int columns = ip[0].size();
    int rows = ip.size();

    //calculate width and height and make it global or a member objects
    //so that you dont have to calculate size everywhere.
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
        {
            if(!res.count(index)) //If the sink has not been found
                getTheSink(ip, res, index);
            index++;
        }

    for(auto val : res) //Counting the no of elements in a basin/elements that have this element as sink.
    {
        retVal[val.second] += 1;
    }

    for(auto val : retVal) //Put the result in a priority queue
    {
        pq.push(val.second);
    }

    return pq;
}
/*******************************************************************************************************************/
/*
 * Problem:
 *     Given a directed graph, check whether the graph contains a cycle or not.
 *     Your function should return true if the given graph contains at least one cycle,
 *     else return false. For example, the following graph contains three cycles 0->2->0, 0->1->2->0 and 3->3,
 *     so your function must return true.
 *
 *
 * Solution:
 *     To detect a back edge, we can keep track of vertices currently in recursion stack of function for DFS traversal.
 *     If we reach a vertex that is already in the recursion stack, then there is a cycle in the tree.
 *
 * */
bool detectACycleInADirectedGraphUtil(vvi g, int src, set<int>& visited, set<int>& currentSet)
{
    if(src >= g.size())
        return false;

    for(auto val : g[src])
    {
        if(visited.count(val))
        {
            if(currentSet.count(val))
                return true;
            continue;
        }
        visited.insert(val);
        currentSet.insert(val);
        bool retVal = detectACycleInADirectedGraphUtil(g, val, visited, currentSet);
        if(retVal == true)
            return retVal;
        currentSet.erase(val);

    }
    return false;

}
/*
 * Problem: Using DFS search for the presence of a key node.
 * */
bool IKSolution::detectACycleInADirectedGraph(vvi g)
{
    set<int> visited;
    set<int> currentSet;
    int index = 0;

    for(auto val : g)
    {
        if(!visited.count(index))
        {
            visited.insert(index);
            currentSet.insert(index);
            if(detectACycleInADirectedGraphUtil(g, index, visited, currentSet) == true)
                return true;
            currentSet.erase(index);
        }

        index++;
    }

    return false;
}
/*******************************************************************************************************************/
/*  Problem:
 *      This was asked during the mock at IK
 *      A file has all the nodes and edges stored as x, y coordinates. You have to find the distance between two coordinates.
 *
 *
 * */



int getDistance(pii src, pii val)
{
    int sum = pow((src.first - val.first), 2)  + pow((src.second - val.second), 2);
    cout << "distance = " << sqrt(sum) << "\n";

    return sqrt(sum);
}

int findDistanceBetweenPointsUtil(mplii g, pii src, pii dest, spii visited, int cDist)
{
    cout << src.first << " " << src.second << " " << dest.first << " " << dest.second << " \n";

    if(!g.count(src))
    {
        cout << "src is not a part of map \n";
        return -1;
    }

    if(src == dest)
    {
        cout << "Meet the destination " << cDist << " \n";
        return cDist;
    }

    for(auto val : g[src])
    {
        if(visited.count(val))
            continue;
        visited.insert(val);

        int dist = getDistance(src,val);
        cDist += dist;
        int retVal = findDistanceBetweenPointsUtil(g, val, dest, visited, cDist);
        if(retVal != -1)
            return retVal;
        cDist -= dist;

    }

    return -1;
}


/*
 *
 *
 * */
int IKSolution::findDistanceBetweenPoints(mplii g, pii src, pii dest)
{
    int cDist = 0;
    spii visited;
    cout << "\n     ******* findDistanceBetweenPoints \n";
    visited.insert(src);
    int resVal = findDistanceBetweenPointsUtil(g, src, dest, visited, cDist);
    cout << "resVal =  " << resVal << " \n";
    return resVal;
}

/*******************************************************************************************************************/


