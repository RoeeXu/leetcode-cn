/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0855.cpp
* Author:   roeexu
* Date:     2019-12-13 12:06:59
* Brief:
****************************************************/

class ExamRoom {
public:
    set<int> s;
    int n;

    ExamRoom(int N) {
        n = N;
    }
    
    int seat() {
        int dist = *s.begin(), pre = -1, student = 0;
        if(s.size() > 0)
        {
            for(auto i : s)
            {
                if(pre != -1)
                {
                    int t = (i - pre) / 2;
                    if(t > dist)
                    {
                        dist = t;
                        student = pre + t;
                    }
                }
                pre = i;
            }
            if(n - 1 - *s.rbegin() > dist) student = n - 1;
        }
        s.insert(student);
        return student;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */


 // mine
// class ExamRoom {
// public:
//     set<int> b;
//     int n;

//     ExamRoom(int N) {
//         n = N;
//     }
    
//     int seat() {
//         int res = -1;
//         if(b.size() == 0) {b.insert(0);res = 0;}
//         else if(b.size() == 1)
//         {
//             int idx = *b.begin();
//             if(n - 1 - idx > idx) {b.insert(n - 1);res = n-1;}
//             else {b.insert(0);res = 0;}
//         }
//         else
//         {
//             int aim_idx = -1, aim_len = -1, idx, len;
//             set<int>::iterator it;
//             it = b.begin();
//             if(*it != 0)
//             {
//                 len = *it - 1;
//                 idx = 0;
//                 if((aim_idx == -1) || (aim_len < len) || (aim_len == len && aim_idx > idx)) { aim_idx = idx; aim_len = len; }
//             }
//             it = b.end();
//             it--;
//             if(*it != n - 1)
//             {
//                 len = n - *it - 2;
//                 idx = n - 1;
//                 if((aim_idx == -1) || (aim_len < len) || (aim_len == len && aim_idx > idx)) { aim_idx = idx; aim_len = len; }
//             }
//             it = b.begin();
//             int idx1 = *it;
//             it++;
//             int idx2 = *it;
//             for(int i = 0; i < b.size() - 1; i++)
//             {
//                 if(idx2 > idx1 + 1)
//                 {
//                     len = (idx2 - idx1 - 2) / 2;
//                     idx = idx1 + len + 1;
//                     if((aim_idx == -1) || (aim_len < len) || (aim_len == len && aim_idx > idx)) { aim_idx = idx; aim_len = len; }
//                 }
//                 idx1 = idx2;
//                 it++;
//                 idx2 = *it;
//             }
//             b.insert(aim_idx);
//             res = aim_idx;
//         }
//         return res;
//     }
    
//     void leave(int p) {
//         b.erase(p);
//     }
// };

// /**
//  * Your ExamRoom object will be instantiated and called as such:
//  * ExamRoom* obj = new ExamRoom(N);
//  * int param_1 = obj->seat();
//  * obj->leave(p);
//  */

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

