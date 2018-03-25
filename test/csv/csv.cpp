//
// Created by PC on 2018/2/9.
//

#include "csv.h"

void csv::split(string str,string separator,vector<string> &result)
{//对每一行以逗号为分隔符进行分割
    result.clear();
    int cutAt;
    while( (cutAt = str.find_first_of(separator)) != str.npos )
    {
        if(cutAt > 0)
        {
            result.push_back(str.substr(0, cutAt));
        }
        str = str.substr(cutAt + 1);
    }
    if(str.length() > 0)
    {
        result.push_back(str);
    }
}