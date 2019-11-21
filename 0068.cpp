/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0068.cpp
* Author:   roeexu
* Date:     2019-11-21 16:41:00
* Brief:
****************************************************/

class Solution {
public:
    string line_format(vector<string>& words, int l, int r, int maxWidth, bool b)
    {
        string log = "";
        int width = 0, n = r - l;
        if(b || n == 0)
        {
            for(int i = l; i <= r; i++)
            {
                log += words[i];
                if(i != r) log += ' ';
            }
            width = log.length();
            for(int i = 0; i < maxWidth - width; i++)
                log += ' ';
        }
        else
        {
            for(int i = l; i <= r; i++)
                width += words[i].length();
            int remain = maxWidth - width;
            int gap = remain / n, m;
            remain = remain - gap * n;
            for(int i = l; i < r; i++)
            {
                log += words[i];
                m = (i - l) < remain ? gap + 1 : gap;
                while(m-- > 0) log += ' ';
            }
            log += words[r];
        }
        return log;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int l = 0, r = 0, width = words[0].length();
        for(int i = 1; i < words.size(); i++)
        {
            if(width + 1 + words[i].length() > maxWidth)
            {
                res.push_back(line_format(words, l, r, maxWidth, 0));
                l = i;
                r = i;
                width = words[i].length();
            }
            else
            {
                r++;
                width += 1 + words[i].length();
            }
        }
        res.push_back(line_format(words, l, r, maxWidth, 1));
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

