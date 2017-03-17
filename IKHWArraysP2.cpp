/*
 * IKHWArraysP2.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: raghav
 */

#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"

bool isPali(string s)
{
    if( s == string(s.rbegin(), s.rend()))
        return true;

    return false;
}

int IKSolution::nextPalindrome(int iInputNum)
{
    DEBUG_DEBUG(cout << "iInputNum = " << iInputNum << "\n");
    int nextPali = 0;

    /* Convert the number to a string */
    string s = to_string(iInputNum);

    int middle = (s.size() -1)/2 ;

    if(s[middle] != '9')
    {
        if(s.size() % 2)
        {
            string prefix = s.substr(0,middle);
            string suffix = s.substr(middle + 1);
            DEBUG_DEBUG(cout << "prefix = " << prefix << " suffix = " << suffix << "\n");

            if((suffix > prefix) || (prefix.size() == 0))
            {
                s[middle] = s[middle] + 1;
            }
            suffix = string(prefix.rbegin(), prefix.rend());

            string ret = s.substr(0, middle + 1) + suffix;
            DEBUG_DEBUG(cout << "prefix = " << prefix << " suffix = " << suffix <<  "\n");
            DEBUG_DEBUG(cout << "ret = " << ret << "\n");
            nextPali = stoi(ret);
            return nextPali;
        }
        else
        {

            string prefix = s.substr(0,middle + 1);
            string suffix = s.substr(middle + 1);
            DEBUG_DEBUG(cout << "prefix = " << prefix << " suffix = " << suffix << "\n");

            if(suffix > prefix)
            {
                prefix = to_string(stoi(prefix) + 1);
            }
            suffix = string(prefix.rbegin(), prefix.rend());

            string ret = prefix + suffix;
            DEBUG_DEBUG(cout << "prefix = " << prefix << " suffix = " << suffix <<  "\n");
            DEBUG_DEBUG(cout << "ret = " << ret << "\n");
            nextPali = stoi(ret);
            return nextPali;


        }
    }
    else
    {

        if(s.size() % 2)
        {
            string prefix = s.substr(0,middle);
            string suffix = s.substr(middle + 1);
            DEBUG_DEBUG(cout << "prefix = " << prefix << " suffix = " << suffix << "\n");

            if((suffix > prefix))
            {
                prefix = to_string(stoi(prefix) + 1);
            }
            suffix = string(prefix.rbegin(), prefix.rend());

            string ret = prefix + "0" + suffix;
            DEBUG_DEBUG(cout << "prefix = " << prefix << " suffix = " << suffix <<  "\n");
            DEBUG_DEBUG(cout << "ret = " << ret << "\n");
            nextPali = stoi(ret);
            return nextPali;
        }
        else
        {
            string prefix = s.substr(0,middle + 1);
            string suffix = s.substr(middle + 1);
            DEBUG_DEBUG(cout << "prefix = " << prefix << " suffix = " << suffix << "\n");

            if(suffix >= prefix)
            {
                int oldsize = prefix.size();
                prefix = to_string(stoi(prefix) + 1);
                if(prefix.size() > oldsize)
                {
                    suffix = string(prefix.rbegin() + 1, prefix.rend());
                }
                else
                {
                    suffix = string(prefix.rbegin(), prefix.rend());
                }
            }
            else
            {
                suffix = string(prefix.rbegin(), prefix.rend());
            }

            string ret = prefix + suffix;
            DEBUG_DEBUG(cout << "prefix = " << prefix << " suffix = " << suffix <<  "\n");
            DEBUG_DEBUG(cout << "ret = " << ret << "\n");
            nextPali = stoi(ret);
            return nextPali;

        }

    }

    return nextPali;
}

void printVector(vector<int> v)
{
    for(auto it : v)
    {
        DEBUG_DEBUG(cout << it << " ");
    }
    DEBUG_DEBUG(cout << "\n");
}


vector<int> IKSolution::AlternatePosNegative(vector<int> vec)
{

    int lastPosindex = 0;
    int lastNegindex = 0;
    printVector(vec);
    DEBUG_DEBUG(cout << " \n");

    for(int index = 1; index < vec.size(); index++)
    {
        DEBUG_DEBUG(cout << "value processed =  " << vec[index] << "  ");
        if(vec[index] < 0 && (vec[lastPosindex + 1] > 0)  )
        {
            int temp = vec[lastPosindex + 1];
            vec[lastPosindex + 1] = vec[index];
            for(int j = index; j > (lastPosindex + 2); j--)
            {
                vec[j] = vec[j-1];
            }
            vec[lastPosindex + 2] = temp;
            lastPosindex = lastPosindex + 2;
            printVector(vec);
            lastNegindex = index;
        }
        else if(vec[index] > 0 && (vec[lastNegindex + 1] < 0))
        {

            int temp = vec[lastNegindex + 1];
                        vec[lastNegindex + 1] = vec[index];
                        for(int j = index; j > (lastNegindex + 2); j--)
                        {
                            vec[j] = vec[j-1];
                        }
                        vec[lastNegindex + 2] = temp;
                        lastNegindex = lastNegindex + 2;
                        printVector(vec);
                        lastPosindex = index;
        }
    }
    return vec;
}


vector<pair<int,int>> IKSolution::skyLine(vvi buildings)
{
    vector<pair<int,int>> res;
    priority_queue<pair<int,int>> mypq;
    int omh = 0;
    int index = 0;
    int i = 0;
    int height;
    int xb;
    int xe;

    while(1)
    {
        if(index == buildings.size())
        {
            if(mypq.empty())
                break;
        }

        if(index < buildings.size())
        {
            height = buildings[index][1];
            xb = buildings[index][0];
            xe = buildings[index][2];
        }

        /* Check if there is a beginning */
        if( (index < buildings.size()) && (i == xb) )
        {
            DEBUG_TRACE(cout << i << " Before Insert: next x = " << xb << height  << xe << " \n");
            pair<int,int> p;

            if(!mypq.empty())
            {
                p = mypq.top();
                omh = p.first;
            }
            else
                omh = 0;

            mypq.push(make_pair(height,xe));
            p = mypq.top();
            if(p.first > omh)
            {
                DEBUG_DEBUG(cout << " New lining after Add " << i << " " << height << " \n");
                res.push_back(make_pair(i,height) );
            }
            index++;
        }
        else
        {
            if(index < buildings.size())
                DEBUG_TRACE(cout << "Before delete: next x = " << xb <<  height  << xe << " \n");

            /* If there is an end to the top, pop all the one;s that are not valid anymore */
            if(!mypq.empty())
            {
                pair<int,int> p = mypq.top();
                bool popped = false;
                int lastpopval = p.first;
                while(p.second <= i)
                {
                    popped = true;
                    mypq.pop();
                    if(!mypq.empty())
                    {
                        p = mypq.top();
                        lastpopval = p.first;
                    }
                    else
                    {
                       lastpopval = 0;
                       break;
                    }
                }
                if(popped == true)
                {
                    DEBUG_DEBUG(cout << " New lining after Remove " << i << " " << lastpopval << " \n");
                    res.push_back(make_pair(i,lastpopval));
                }
            }
        }
        i++;
    }
    return res;
}
