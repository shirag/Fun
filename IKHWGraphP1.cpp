/*
 * IKHWGraphP1.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: GouriShivani
 */


#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include "IKSolution.hpp"
#include <algorithm>
#include <queue>


/************************************************************************************************/
int printAllPathsInAGraphUtil(vi& g, vector<int>& v, int &src, int& dest, vvi& paths)
{

    if(src == dest)
    {

        for(unsigned int i = 0; i < v.size(); i++ )
        {
            cout << "path = " << v[i];
        }
        cout << " " << src;
        vi path(v);
        paths.push_back(path);
        return 1;
    }

    v.push_back(src);

    for(unsigned int i = 0; i < g.size(); i++)
        printAllPathsInAGraphUtil(g, v, g[i], dest,paths);

    v.erase(v.end()-1);

    return 0;
}


/* Problem: Print all paths.
 * Example:
 * Approach:
 * Complexity:
 * Space Complexity:
 * Any other better approach:
 * Corner case:
 * Take away:
 */
int IKSolution::printAllPathsInAGraph(vvi& g, int src, int dest)
{
    cout << "no of vertex = " << g.size();

    vector<int> s;
    vvi paths;

    printAllPathsInAGraphUtil(g[src], s, src, dest,paths);

    for(unsigned int i = 0; i < paths.size(); i++)
    {
        cout << " size of path " << i << " = "  << paths[i].size();
    }

    return 0;
}


/************************************************************************************************/

/* Problem: Count the number of islands
 * Example:
 * Approach:
 * Complexity:
 * Space Complexity:
 * Any other better approach:
 * Corner case:
 * Take away:
 */


/************************************************************************************************/
int depthFirstSearchUtil(vvi & W, int node, vector<bool>& flag)
{

    cout << "processing node " << node << "\n";
    flag[node] = 1;

    for(vector<int>::iterator it = W[node].begin(); it != W[node].end(); it++)
    {
        if(flag[*it] == 0)
        {
            depthFirstSearchUtil(W,*it,flag);
        }
    }

    return 0;

}

/* Problem: Count the number of connected components
 * Example:
 * Approach:
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
            depthFirstSearchUtil(W,i,flag);

            for(j = 0; j < n; j++ )
            {
                if(flag[j] == 0)
                {
                    cout << " j = " << j << " not processed \n";
                    counter++;
                    break;
                }

                if(j == n)
                    break;
            }
        }
    }

    return counter;
}

/* Problem:
 * Example:
 * Approach:
 * Complexity:
 * Space Complexity:
 * Any other better approach:
 * Corner case:
 * Take away:
 */


int getNextLocation(int rows, int columns, int startx, int starty, lpii& vt)
{

    int nx = startx + 1;
    int ny = starty + 2;

#if 1
    cout << "\n" << " anx  = "  << nx ;
    cout << " ny  = "  << ny ;
#endif

    if((nx < columns) && (ny < rows))
        vt.push_back(make_pair(nx,ny));
    //else
        //cout << " Invalid location \n";

    nx = startx + 2;
    ny = starty + 1;
#if 1
    cout << "\n" << " bnx  = "  << nx ;
    cout << " ny  = "  << ny << "\n" ;
#endif

    if((nx < columns) && (ny < rows))
        vt.push_back(make_pair(nx,ny));
    //else
        //cout << " Invalid location \n";
#if 1
   nx = startx - 1;
   ny = starty - 2;

   cout << "\n" << " nx  = "  << nx ;
   cout << " ny  = "  << ny ;

   if((nx >= 0) && (ny >= 0))
       vt.push_back(make_pair(nx,ny));
   //else
       //cout << " Invalid location \n";

   nx = startx - 2;
   ny = starty - 1;

   cout << "\n" << " nx  = "  << nx ;
   cout << " ny  = "  << ny << "\n" ;


   if((nx >= 0) && (ny >= 0))
       vt.push_back(make_pair(nx,ny));
   //else
       //cout << " Invalid location \n";
#endif

   nx = startx - 1;
   ny = starty + 2;

   cout << "\n" << " nx  = "  << nx ;
   cout << " ny  = "  << ny ;

   if((nx >= 0) && (ny >= 0))
       vt.push_back(make_pair(nx,ny));
   //else
       //cout << " Invalid location \n";

   nx = startx - 2;
   ny = starty + 1;

   cout << "\n" << " nx  = "  << nx ;
   cout << " ny  = "  << ny ;

   if((nx >= 0) && (ny >= 0))
       vt.push_back(make_pair(nx,ny));
    //else
       //cout << " Invalid location \n";

   nx = startx + 2;
   ny = starty - 1;

   cout << "\n" << " nx  = "  << nx ;
   cout << " ny  = "  << ny ;

   if((nx >= 0) && (ny >= 0))
       vt.push_back(make_pair(nx,ny));

   nx = startx + 1;
   ny = starty - 2;

   cout << "\n" << " nx  = "  << nx ;
   cout << " ny  = "  << ny ;

   if((nx >= 0) && (ny >= 0))
       vt.push_back(make_pair(nx,ny));

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
 * Complexity:
 * Space Complexity:
 * Any other better approach:
 * Corner case:
 * Take away:
 */
int IKSolution::knightsTourOnChessBoard(int rows, int columns, int sx, int sy, int ex, int ey)
{
    unsigned int level = 0;
    int index = 0;
    lpii lpop;  //List used to push
    lpii lpush; //List used to pop
    qlpii qm;   //Main processing queue. Above two lists are pushed and popped
    spii flags; //Set of visited flag

    pii end = make_pair(ex,ey); //Destination

    lpush.push_back(make_pair(sx, sy));
    qm.push(lpush);
    lpush.clear();

    while(!qm.empty())
    {
        lpop = qm.front();
        qm.pop();

        lpush.clear(); index = 0;
        for(lpii::iterator it = lpop.begin(); it != lpop.end(); it++)
        {
            pii cl = *it;
            spii::iterator it1 = flags.find(cl);
            if(it1 != flags.end())
                continue;

            cout << "level:" << level << " index: " << index++;
            cout << " x = " << cl.first; cout << " y = " << cl.second << "\n";

            if(cl == end)
            {
                cout<< " We found the destination at level = " << level << "\n";
                return level;
            }

            flags.insert(cl);
            lpii vtt;
            getNextLocation(rows, columns, cl.first, cl.second, vtt);
            if(!vtt.empty())
                lpush.insert(lpush.end(),vtt.begin(), vtt.end());

        }
        if(!lpush.empty())
            qm.push(lpush);

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
            //cout << "oneDiff " <<  begin << " "  << *it << "\n";
            l.push_back(*it);
            if(mp.find(*it) == mp.end())
                mp[*it] = begin;
        }
    }

    return 0;
}


/* Problem:
           Convert string a to b using a dictionary of words
 * Example:
 *         dictionary: {"cat", "bat", "hat", "bad", "had"}
           a = "bat"
           b = "had"
           solution:
           "bat" -> "bad" -> "had"
 * Approach:
 *         Graph BFS search. Build the graph as your traverse. For every node visited store the
 *         src node in a map. When you hit the destination come out of the search. Populate the contents
 *         of the map onto a stack and then print contents of the stack.
 * Complexity: n * n * m(where n is the no of strings and m is chars in each string)
 * Space Complexity: O(1)
 * Any other better approach:
 *         For finding the difference you can use a map instead of going over the loop.
 *         By doing that you will use n*n*m space and then n time and n*n*m space.
 * Corner case:
 * Take away:
 *        Identify the connection function.
 */
int IKSolution::convertAString(ls& dict, string& begin, string& end)
{
    unsigned int level = 0;
    int index = 0;

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

        lpush.clear(); index = 0;
        for(ls::iterator it = lpop.begin(); it != lpop.end(); it++)
        {
            string begin = *it;
            ss::iterator it1 = flags.find(begin);
            if(it1 != flags.end())
                continue;

            cout << "level:" << level << " index: " << index++;
            cout << " string = " << begin << "\n";

            if(begin == end)
            {
                cout<< " We found the destination at level = " << level << "\n";
                break;
            }

            flags.insert(begin);
            ls vtt;
            getNextLevelStrings(dict, begin, vtt, mp);
            if(!vtt.empty())
                lpush.insert(lpush.end(),vtt.begin(), vtt.end());

        }
        if(!lpush.empty())
            qm.push(lpush);

        level++;
    }

    stack<string> s;
    string toF(end);

    while(1)
    {
        //cout << " " << toF;
        if(!toF.empty())
            s.push(toF);

        map<string, string>::iterator it = mp.find(toF);
        if(it == mp.end())
        {
            break;
        }
        toF = it->second;
    }
    cout << "\n";

    do{
        cout << s.top();
        s.pop();
    }while(!s.empty() && (cout << " --> "));

    return level;
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

    cout << "processing node val " << tn.val << "\n";

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
 *          Generate the graph using input words:Compare eac word with the next one.
 *          When you found a different char, build a graph vertex and connect corresponding edges.
            Once the graph is generated, do a DFS search and while doing the search push leaf to a stack.
            Print content of the stack.
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
