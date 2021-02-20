/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0190.cpp
* Author:   roeexu
* Date:     2021-02-20 17:04:54
* Brief:
****************************************************/
 
class Solution {
  public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0, power = 31;
    while (n != 0) {
      ret += (n & 1) << power;
      n = n >> 1;
      power -= 1;
    }
    return ret;
  }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

