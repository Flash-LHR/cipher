#include <bits/stdc++.h>
using namespace std;

class keySchedule {
public:
    static bool randBool() {
        return rand() % 2;
    }

    static void genKey() {
        string key = "";
        srand(time(NULL));
        for(int i = 0; i < 8; ++i) {
            bool cs = 0;
            for(int j = 0; j < 7; ++j) {
                key += randBool() + '0';
                cs ^= key.back() - '0';
            }
            key += cs + '0';
        }
        ofstream out("../private/key.txt", ios::out);
        out << key << "\n";
        out.close();
    }

    static int PC1[56], r[16], PC2[56];
    static vector<bool> roundKey[16];

    static vector<bool> getKey() {
        ifstream in("../private/key.txt");
        string keyStr;
        in >> keyStr;
        vector<bool> key(64);
        for(int i = 0; i < 64; ++i) key[i] = keyStr[i] - '0';
        return key;
    }

    static vector<bool> SLC(vector<bool> A, int r) {
        vector<bool> B(28);
        for(int i = 0; i < 28 - r; ++i) B[i] = A[i + r];
        for(int i = 28 - r; i < 28; ++i) B[i] = A[i - 28 + r];
        return B;
    }

    static void genRoundKey() {
        vector<bool> key = getKey();
        vector<bool> C(28), D(28), temp(56);
        for(int i = 0; i < 28; ++i) {
            C[i] = key[PC1[i] - 1];
            D[i] = key[PC1[i + 28] - 1];
        }
        for(int i = 0; i < 16; ++i) {
            C = SLC(C, r[i]), D = SLC(D, r[i]);
            for(int j = 0; j < 28; ++j) {
                temp[j] = C[j];
                temp[j + 28] = D[j];
            }
            for(int j = 0; j < 56; ++j) roundKey[i][j] = temp[PC2[j] - 1];
        }
    }

    static vector<bool> getRoundKey(int round) {
        return roundKey[round];
    }
};

int keySchedule::PC1[56] = {57, 49, 41, 33, 25, 17,  9,
                             1, 58, 50, 42, 34, 26, 18,
                            10,  2, 59, 51, 43, 35, 27,
                            19, 11,  3, 60, 52, 44, 36,
                            63, 55, 47, 39, 31, 23, 15,
                             7, 62, 54, 46, 38, 30, 22,
                            14,  6, 61, 53, 45, 37, 29,
                            21, 13,  5, 28, 20, 12,  4};

int keySchedule::r[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

int keySchedule::PC2[56] = {14, 17, 11, 24,  1,  5,
                             3, 28, 15,  6, 21, 10,
                            23, 19, 12,  4, 26,  8,
                            16,  7, 27, 20, 13,  2,
                            41, 52, 31, 37, 47, 55,
                            30, 40, 51, 45, 33, 48,
                            44, 49, 39, 56, 34, 53,
                            46, 42, 50, 36, 29, 32};

vector<bool> keySchedule::roundKey[16];
