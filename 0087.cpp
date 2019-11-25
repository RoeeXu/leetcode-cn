/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0087.cpp
* Author:   roeexu
* Date:     2019-11-25 16:37:40
* Brief:
****************************************************/

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.size() != s2.size()) return 0;
		if (s1 == s2) return 1;
		string ss1(s1);
		string ss2(s2);
		sort(ss1.begin(), ss1.end());
		sort(ss2.begin(), ss2.end());
		if (ss1 != ss2) return 0;
		for (int i = 1; i < s1.size(); i++) {
			if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) return 1;
			if(isScramble(s1.substr(0, i), s2.substr(s2.size() - i)) && isScramble(s1.substr(i), s2.substr(0, s2.size() - i))) return 1;
		}
		return 0;
	}
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

