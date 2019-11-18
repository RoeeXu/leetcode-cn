/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0043.cpp
* Author:   roeexu
* Date:     2019/11/18 13:20:14
* Brief:
****************************************************/

class Solution {
public:
    // best
    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0') return "0";
        int n1 = num1.size(), n2 = num2.size(), tmp;
        string res(n1 + n2, '0');
        for(int i = n2 - 1; i >= 0; i--){
            for(int j = n1 - 1; j >= 0; j--){
                tmp = res[i + j + 1] - '0' + (num1[j] - '0') * (num2[i] - '0');
                res[i + j + 1] = tmp % 10 + '0';
                res[i + j] += tmp / 10;
            }
        }
        for(int i = 0; i < n1 + n2; i++)
            if(res[i] != '0')
                return res.substr(i);
        return "0";
    }

    // mine 2
    // string multiply(string num1, string num2) {
    //     int n1 = num1.length(), n2 = num2.length();
    //     if(num1[0] == '0' || num2[0] == '0') return "0";
    //     int *pre = new int[n1 + n2]();
    //     string res(n1 + n2, '0');
    //     for(int i = n1 - 1; i >= 0; i--)
    //         for(int j = n2 - 1; j >= 0; j--)
    //             pre[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
    //     int up = 0, tmp;
    //     for(int i = n1 + n2 - 1; i >= 0; i--)
    //     {
    //         tmp = pre[i] + up;
    //         res[i] = tmp % 10 + '0';
    //         up = tmp / 10;
    //     }
    //     for(int i = 0; i < n1 + n2; i++)
    //         if(res[i] != '0')
    //             return res.substr(i);
    //     return res;
    // }

    // mine 1
    // string mul_one(string big, int one, int zero)
    // {
    //     int up = 0, n = big.length(), tmp;
    //     string res = "";
    //     for(int i = 0; i < n; i++)
    //     {
    //         tmp = (big[n - 1 - i] - '0') * one + up;
    //         up = tmp / 10;
    //         res.insert(res.begin(), tmp % 10 + '0');
    //     }
    //     if(up != 0)
    //         res.insert(res.begin(), up + '0');
    //     for(int i = 0; i < zero; i++)
    //     {
    //         res += '0';
    //     }
    //     return res;
    // }

    // string addition(string x, string y)
    // {
    //     int n1 = x.length(), n2 = y.length();
    //     if(n1 > n2) return addition(y, x);
    //     int up = 0, tmp;
    //     string res = "";
    //     for(int i = 0; i < n1; i++)
    //     {
    //         tmp = x[n1 - 1 - i] - '0' + y[n2 - 1 - i] - '0' + up;
    //         up = tmp / 10;
    //         res.insert(res.begin(), tmp % 10 + '0');
    //     }
    //     if(n1 != n2)
    //         for(int i = n1; i < n2; i++)
    //         {
    //             tmp = y[n2 - 1 - i] - '0' + up;
    //             up = tmp / 10;
    //             res.insert(res.begin(), tmp % 10 + '0');
    //         }
    //     if(up != 0)
    //         res.insert(res.begin(), up + '0');
    //     return res;
    // }


    // string multiply(string num1, string num2) {
    //     int n1 = num1.length(), n2 = num2.length();
    //     if(num1[0] == '0' || num2[0] == '0') return "0";
    //     if(n1 > n2) return multiply(num2, num1);
    //     string res = "0", tmp;
    //     for(int i = 0; i < n1; i++)
    //     {
    //         tmp = mul_one(num2, num1[i] - '0', n1 - 1 - i);
    //         res = addition(res, tmp);
    //     }
    //     return res;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

