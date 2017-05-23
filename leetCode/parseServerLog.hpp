/*
 * parserLogServer.hpp
 *
 *  Created on: May 18, 2017
 *      Author: Raghav Navada
 */

#ifndef _PARSERLOGSERVER_HPP_
#define _PARSERLOGSERVER_HPP_

#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

using namespace std;

/*
 * Class LogTable:
 *
 * Description:
 *     This generates all the tables after paring an input file stream. Stores the result in a
 *     unordered_map<string,int>. User can invoke the getMostNotFoundIPs() to get the IP addresses with the most
 *     404 error
 * */
class LogTable
{
    public:
        LogTable(ifstream& in);
        vector<string> getMostNotFoundIPs(); //Return a vector of ips with most 404(not found) error.
        ~LogTable();

    private:
        unordered_map<string,int> notFoundMap;
};



#endif /* _PARSERLOGSERVER_HPP_ */
