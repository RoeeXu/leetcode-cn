/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     1736.cpp
* Author:   roeexu
* Date:     2021-01-29 15:00:20
* Brief:
****************************************************/
 
class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?')
        {
            if (time[1] == '?' || time[1] < '4') time[0] = '2';
            else time[0] = '1';
        }
        if (time[1] == '?')
        {
            if (time[0] == '2') time[1] = '3';
            else time[1] = '9';
        }
        if (time[3] == '?') time[3] = '5';
        if (time[4] == '?') time[4] = '9';
        return time;
    }
};   

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

