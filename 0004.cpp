/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0004.cpp
* Author:   roee
* Date:     2019-11-18 23:16:23
* Brief:
****************************************************/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
		int idx1 = -1, idx2 = -1;
		bool isOdd = (sz1 + sz2) % 2 == 1;
		int thisNum, preNum;
		if (nums1.size() == 0)
		{
			thisNum = nums2[0];
			idx2++;
		}
		else if (nums2.size() == 0)
		{
			thisNum = nums1[0];
			idx1++;
		}
		else
		{
			if (nums1[0] > nums2[0])
			{
				thisNum = nums2[0];
				idx2++;
			}
			else
			{
				thisNum = nums1[0];
				idx1++;
			}
		}

		if (sz1 + sz2 == 1)
		{
			return thisNum;
		}

		while (true)
		{
			preNum = thisNum;
			if (idx1 + 1 == sz1)
			{
				idx2++;
				thisNum = nums2[idx2];
			}
			else if (idx2 + 1 == sz2)
			{
				idx1++;
				thisNum = nums1[idx1];
			}
			else
			{
				if (nums1[idx1 + 1] > nums2[idx2 + 1])
				{
					idx2++;
					thisNum = nums2[idx2];
				}
				else
				{
					idx1++;
					thisNum = nums1[idx1];
				}
			}

			int idxSum = (idx1 + 1) + (idx2 + 1);

			if (idxSum == (sz1 + sz2) / 2 + 1)
			{
				if (isOdd)
				{
					return thisNum;
				}
				else
				{
					return double(thisNum + preNum) / 2.0;
				}
			}
		}
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

