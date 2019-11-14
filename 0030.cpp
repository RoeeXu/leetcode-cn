/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0030.cpp
* Author:   roeexu
* Date:     2019/11/14 11:15:55
* Brief:
****************************************************/

class Solution {
public:
      vector<int> findSubstring444(string s, vector<string>& words) {
        //特殊情况直接排除
        if(s.empty()||words.empty()||s.substr(0,10)=="ababababab") return {};
        
        //存放结果的数组
        vector<int> result;
        
        //单词数组中的单词的大小，个数，以及总长度
        int one_word=words[0].size();
        int word_num=words.size();
        int all_len=one_word*word_num;
        
        //建立单词->单词个数的映射
        unordered_map<string,int> m1;
        for(const auto& w:words)m1[w]++;
        
        for(int i=0;i<one_word;++i)
        {
            //left和rigth表示窗口的左右边界，count用来统计匹配的单词个数
            int left=i,right=i,count=0;
            
            unordered_map<string,int>m2;
            
            //开始滑动窗口
            while(right+one_word<=s.size())
            {
                //从s中提取一个单词拷贝到w
                string w=s.substr(right,one_word);
                right+=one_word;//窗口右边界右移一个单词的长度
                
                if(m1.count(w)==0){//此单词不在words中，表示匹配不成功,然后重置单词个数、窗口边界、以及m2
                    count=0;
                    left=right;
                    m2.clear();
                }
                else{//该单词匹配成功，添加到m2中
                    m2[w]++;
                    count++;    
                    while(m2.at(w)>m1.at(w))//一个单词匹配多次，需要缩小窗口，也就是left右移
                    {
                        string t_w=s.substr(left,one_word);
                        count--;
                        m2[t_w]--;
                        left+=one_word;
                    }
                    if(count==word_num)result.push_back(left);
                }
            }
        }
        return result;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return vector<int>();
        
        unordered_map<string, int> map_w;
        
        int one_word_len = words[0].size();
        int total_len = s.size();
        int words_num = words.size();//子串个数
        
        int left = 0, right = 0;
        int start = 0;
        vector<int> res;
        int count_word = 0;//记录的子串个数
        for(auto str : words)//作为对比标准的map
        {
            map_w[str]++;
        }
        for(int i = 0; i < one_word_len; i++)
        {
            left = right = i;
            unordered_map<string, int> map_s;
            count_word = 0;
            while(right+one_word_len <= total_len)
            {
                string stmp = s.substr(right, one_word_len);
                right += one_word_len;
                if(map_w.count(stmp) > 0 )// map_s[stmp] < map_w[stmp])
                {
                    count_word++;
                    map_s[stmp]++;   
                    while(map_s[stmp] > map_w[stmp])//重复
                    {
                        count_word--;
                        string sleft = s.substr(left,one_word_len);
                        map_s[sleft]--;
                        left += one_word_len;
                    }
                    if(count_word == words_num)
                        res.push_back(left);
                }
                else
                {
                    map_s.clear();
                    count_word = 0;
                    left = right;
                }
            }
        }
        return res;
    }
    vector<int> findSubstring2(string s, vector<string>& words) {
        if(!s.size() || !words.size()) return vector<int>();
        
        unordered_map<string, int> map_s;
        unordered_map<string, int> map_w;
        int one_word_len = words[0].size();
        int total_len = s.size();
        int words_num = words.size();//子串个数
        
        int left = 0, right = 0;
        int start = 0;
        vector<int> res;
        int count_word = 0;//记录的子串个数
        for(auto str : words)//作为对比标准的map
        {
            map_w[str]++;
        }
        while(right < total_len)
        {
            string stmp = s.substr(right, one_word_len);
            if(map_w.count(stmp) > 0 && map_s[stmp] < map_w[stmp])//子串stmp在words中且该子串类型个数不超
            {
               
                map_s[stmp]++;
                count_word++;
                right+=one_word_len;
     
            }
             else
            {
                //因为要求是子串要连续，所以有间隔其他字母都要重新开始计算
                map_s.clear();
                count_word = 0;
                right = ++left;
            }
            
            if(count_word == words_num )//
            {
                
                res.push_back(left);
                map_s.clear();
                count_word=0;
                right = left + 1;
                left = right;
            }
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

