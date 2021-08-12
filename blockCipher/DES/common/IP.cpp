#include <vector>
using namespace std;

class IP {
    static int P[64], PInv[64];

    static vector<int> afterIP(const vector<int>& PT) {
        vector<int> CT(64);
        for(int i = 0; i < 64; ++i) CT[i] = PT[P[i] - 1];
        return CT;
    }

    static vector<int> afterIPInv(const vector<int>& CT) {
        vector<int> PT(64);
        for(int i = 0; i < 64; ++i) PT[i] = CT[PInv[i] - 1];
        return PT;
    }
};

int IP::P[64] = {58, 50, 42, 34, 26, 18, 10,  2,
                 60, 52, 44, 36, 28, 20, 12,  4,
                 62, 54, 46, 38, 30, 22, 14,  6,
                 64, 56, 48, 40, 32, 24, 16,  8,
                 57, 49, 41, 33, 25, 17,  9,  1,
                 59, 51, 43, 35, 27, 19, 11,  3,
                 61, 53, 45, 37, 29, 21, 13,  5,
                 63, 55, 47, 39, 31, 23, 15,  7};

int IP::PInv[64] = {40,  8, 48, 16, 56, 24, 64, 32,
                    39,  7, 47, 15, 55, 23, 63, 31,
                    38,  6, 46, 14, 54, 22, 62, 30,
                    37,  5, 45, 13, 53, 21, 61, 29,
                    36,  4, 44, 12, 52, 20, 60, 28,
                    35,  3, 43, 11, 51, 19, 59, 27,
                    34,  2, 42, 10, 50, 18, 58, 26,
                    33,  1, 41,  9, 49, 17, 57, 25};
