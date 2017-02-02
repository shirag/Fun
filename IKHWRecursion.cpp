/*


 * IKHWRecursion.cpp
 *
 *  Created on: Jan 31, 2017
 *      Author: GouriShivani
 */


#if 0

int beginIndex = 0;
int endIndex = 0;

int getValuesRecursive(int low, int high, vector<char> v, int k, vector<string>& res);
#if 0
int mainRecursion()
{
    endIndex = 10;
    for(i = 0; i < n; i++)
    {
        getValuesRecursive(i,n-1,k) == k)
    }
}
#endif



vector<string> expressionCreator(string strDigits, int iK)
{

    std::vector<char> data(strDigits.begin(), strDigits.end());
    beginIndex = 0;
    endIndex = data.size()-1;
    vector<string> res;
    int high = data.size()-1;

    for(int i = 0; i < data.size(); i++)
    {
        getValuesRecursive(i, high , data, iK, res);
        return res;
    }

    return res;

}

int getSubSetsUtil(vector<int>& values, vector< set<int> >& resultSet, int index)
{

    return 0;
}


int getSubSets()
{

    vector<int> values = {1, 2};

    vector< set<int> > resultSet;

    for(int i = 0; i < values.size(); i++)
    {
        //resultSet.push_back(values[i]);
        getSubSetsUtil(vector<int>& values, vector< set<int> >& resultSet, int index)

    }

}

int getValuesRecursive(int low, int high, vector<char> v, int k, vector<string>& res)
{
    if(high == beginIndex)
    {
        const char c = v[beginIndex];
        return atoi(&c);
    }

    if(low == endIndex)
    {
        const char c = v[endIndex];
        return atoi(&c);
    }


    int leftVal = getValuesRecursive(beginIndex, low, v, k, res); //left
    int rightVal = getValuesRecursive(low + 1, endIndex, v, k, res); //left

    if((leftVal + rightVal) == k)
    {
        string str1 = to_string(leftVal);
        string str2 = to_string(rightVal);
        string str3 = str1 + "+" + str2 ;
        res.push_back(str3);
    }

    if((leftVal * rightVal) == k)
    {
        string str1 = to_string(leftVal);
        string str2 = to_string(rightVal);
        string str3 = str1 + "+" + str2 ;
        res.push_back(str3);
    }

    leftVal *= (pow(10,v.size()-1-low));
    return (leftVal + (rightVal));
}
#endif
