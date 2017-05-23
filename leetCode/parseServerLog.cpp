/*
 * parseServerLog.cpp
 *
 *  Created on: May 18, 2017
 *      Author: Raghav Navada
 */

#include "parseServerLog.hpp"

using namespace std;

const int clientIpColumnNo = 8;
const int notFoundErrorValueColumnNo = 11;
const string notFoundErrorValueString = "404";

/*
 * Function:
 *     validateIpAddress
 *
 * Input:
 *     const string &ipAddress
 *
 * Output:
 *     true: if its a valid IP.
 *     false: if its an invalid IP.
 *
 * Description:
 *
 * Notes:
 *
 */
bool validateIpAddress(const string &ipAddress)
{
    struct sockaddr_in s;
    int res = inet_pton(AF_INET, ipAddress.c_str(), &(s.sin_addr));
    return res != 0;
}

/*
 * Function:
 *     LogTable constructor.
 * Input:
 *     ifstream& in
 * Output:
 *
 * Description:
 *     Goes over each and every line of the the input filestream and looks for client IP Column, status column,
 *     and notFoundErrorValueString. If everything matches, the data is stored as a pair in <ip, noOfOccurance>
 *     hashmap.
 *
 * Notes:
 *
 */
LogTable::LogTable(ifstream& in)
{
    string line;
    while(getline(in, line))
    {
        istringstream iss(line);
        string word, ip;
        int column = 0;

        if(line[0] == '#') //Ignore comments
            continue;

        while(iss >> word)
        {
            if(column == clientIpColumnNo)
            {
                if(validateIpAddress(word) == true)
                    ip = word;
                else
                    break;
            }

            if(column == notFoundErrorValueColumnNo && word == notFoundErrorValueString)
            {
                if(ip.size() != 0)
                    notFoundMap[ip] += 1;
                break;
            }

            column++;
        }
    }
}

/*
 Function:
 *     LogTable Destructor.
 * Input:

 * Output:
 *
 * Description:
 *     Clears the <ip, noOfOccurance> hashmap.
 * Notes:
 */
LogTable::~LogTable()
{
    notFoundMap.clear();
}

/* Function:
 *     getMostNotFoundIPs()
 *
 * Input:

 * Output:
 *     vector<string> - All IPs that have max no of "not found"(404) occurrences
 *
 * Description:
 *     go over <ip, noOfOccurance> hashmap and store the max found until now.
 *     Update the max info when you come across a new max.
 *
 * Notes:
 */

vector<string> LogTable::getMostNotFoundIPs()
{
    vector<string> maxErrorIp;
    int maxErrorValue = 0;

    for(auto val : notFoundMap)
    {
        if(val.second == maxErrorValue)
            maxErrorIp.push_back(val.first);
        else if(val.second > maxErrorValue)
        {
            maxErrorIp.clear();
            maxErrorValue = val.second;
            maxErrorIp.push_back(val.first);
        }
    }

    return maxErrorIp;
}

