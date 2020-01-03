/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0932.cpp
* Author:   roeexu
* Date:     2020-01-03 19:54:04
* Brief:
****************************************************/
 
class Solution {
public:
    // vector<int> beautifulArray(int N) {
    //     vector<int> res;
    //     if(N == 1) return {1};
    //     else if(N % 2) {
    //         vector<int> tmp = beautifulArray(N / 2);
    //         for(int i = 0; i < N / 2; i++)
    //             res.push_back(2 * tmp[i] + 1);
    //         res.push_back(1);
    //         for(int i = 0; i < N / 2; i++)
    //             res.push_back(2 * tmp[i]);
    //     }
    //     else {
    //         vector<int> tmp = beautifulArray(N / 2);
    //         for(int i = 0; i < N / 2; i++)
    //             res.push_back(2 * tmp[i] - 1);
    //         for(int i = 0; i < N / 2; i++)
    //             res.push_back(2 * tmp[i]);
    //     }
    //     return res;
    // }
    
    // vector<int> beautifulArray(int N) {
    //     vector<int> res(N, 1);
    //     int k = 1;
    //     for(int m = N - 1; m > 1; m >>= 1, k <<= 1) ;
    //     for(int i = 1, t = 1; i < N; t = i, k >>= 1)
    //         for(int j = 0; j < t; j++)
    //             if(res[j] + k <= N) res[i++] = res[j] + k;
    //     return res;
    // }

    vector<int> beautifulArray(int N) {
        vector<int> tmp = {977,465,721,209,849,337,593,81,913,401,657,145,785,273,529,17,945,433,689,177,817,305,561,49,881,369,625,113,753,241,497,993,481,737,225,865,353,609,97,929,417,673,161,801,289,545,33,961,449,705,193,833,321,577,65,897,385,641,129,769,257,513,1,969,457,713,201,841,329,585,73,905,393,649,137,777,265,521,9,937,425,681,169,809,297,553,41,873,361,617,105,745,233,489,985,473,729,217,857,345,601,89,921,409,665,153,793,281,537,25,953,441,697,185,825,313,569,57,889,377,633,121,761,249,505,981,469,725,213,853,341,597,85,917,405,661,149,789,277,533,21,949,437,693,181,821,309,565,53,885,373,629,117,757,245,501,997,485,741,229,869,357,613,101,933,421,677,165,805,293,549,37,965,453,709,197,837,325,581,69,901,389,645,133,773,261,517,5,973,461,717,205,845,333,589,77,909,397,653,141,781,269,525,13,941,429,685,173,813,301,557,45,877,365,621,109,749,237,493,989,477,733,221,861,349,605,93,925,413,669,157,797,285,541,29,957,445,701,189,829,317,573,61,893,381,637,125,765,253,509,979,467,723,211,851,339,595,83,915,403,659,147,787,275,531,19,947,435,691,179,819,307,563,51,883,371,627,115,755,243,499,995,483,739,227,867,355,611,99,931,419,675,163,803,291,547,35,963,451,707,195,835,323,579,67,899,387,643,131,771,259,515,3,971,459,715,203,843,331,587,75,907,395,651,139,779,267,523,11,939,427,683,171,811,299,555,43,875,363,619,107,747,235,491,987,475,731,219,859,347,603,91,923,411,667,155,795,283,539,27,955,443,699,187,827,315,571,59,891,379,635,123,763,251,507,983,471,727,215,855,343,599,87,919,407,663,151,791,279,535,23,951,439,695,183,823,311,567,55,887,375,631,119,759,247,503,999,487,743,231,871,359,615,103,935,423,679,167,807,295,551,39,967,455,711,199,839,327,583,71,903,391,647,135,775,263,519,7,975,463,719,207,847,335,591,79,911,399,655,143,783,271,527,15,943,431,687,175,815,303,559,47,879,367,623,111,751,239,495,991,479,735,223,863,351,607,95,927,415,671,159,799,287,543,31,959,447,703,191,831,319,575,63,895,383,639,127,767,255,511,978,466,722,210,850,338,594,82,914,402,658,146,786,274,530,18,946,434,690,178,818,306,562,50,882,370,626,114,754,242,498,994,482,738,226,866,354,610,98,930,418,674,162,802,290,546,34,962,450,706,194,834,322,578,66,898,386,642,130,770,258,514,2,970,458,714,202,842,330,586,74,906,394,650,138,778,266,522,10,938,426,682,170,810,298,554,42,874,362,618,106,746,234,490,986,474,730,218,858,346,602,90,922,410,666,154,794,282,538,26,954,442,698,186,826,314,570,58,890,378,634,122,762,250,506,982,470,726,214,854,342,598,86,918,406,662,150,790,278,534,22,950,438,694,182,822,310,566,54,886,374,630,118,758,246,502,998,486,742,230,870,358,614,102,934,422,678,166,806,294,550,38,966,454,710,198,838,326,582,70,902,390,646,134,774,262,518,6,974,462,718,206,846,334,590,78,910,398,654,142,782,270,526,14,942,430,686,174,814,302,558,46,878,366,622,110,750,238,494,990,478,734,222,862,350,606,94,926,414,670,158,798,286,542,30,958,446,702,190,830,318,574,62,894,382,638,126,766,254,510,980,468,724,212,852,340,596,84,916,404,660,148,788,276,532,20,948,436,692,180,820,308,564,52,884,372,628,116,756,244,500,996,484,740,228,868,356,612,100,932,420,676,164,804,292,548,36,964,452,708,196,836,324,580,68,900,388,644,132,772,260,516,4,972,460,716,204,844,332,588,76,908,396,652,140,780,268,524,12,940,428,684,172,812,300,556,44,876,364,620,108,748,236,492,988,476,732,220,860,348,604,92,924,412,668,156,796,284,540,28,956,444,700,188,828,316,572,60,892,380,636,124,764,252,508,984,472,728,216,856,344,600,88,920,408,664,152,792,280,536,24,952,440,696,184,824,312,568,56,888,376,632,120,760,248,504,1000,488,744,232,872,360,616,104,936,424,680,168,808,296,552,40,968,456,712,200,840,328,584,72,904,392,648,136,776,264,520,8,976,464,720,208,848,336,592,80,912,400,656,144,784,272,528,16,944,432,688,176,816,304,560,48,880,368,624,112,752,240,496,992,480,736,224,864,352,608,96,928,416,672,160,800,288,544,32,960,448,704,192,832,320,576,64,896,384,640,128,768,256,512};
        vector<int> res;
        for(auto a : tmp) if(a <= N) res.push_back(a);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

