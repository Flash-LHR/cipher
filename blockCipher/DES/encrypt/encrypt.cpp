#include <bits/stdc++.h>
#include "../common/F.cpp"
#include "../common/IP.cpp"
#include "../keySchedule/keySchedule.cpp"
using namespace std;

class encrypt {
public:
    static vector<bool> encryption(vector<bool> P) {
        vector<bool> LR = IP::afterIP(P);
        vector<bool> L(32), R(32), temp(32), RL(64), C(64);
        for(int i = 0; i < 32; ++i) {
            L[i] = LR[i];
            R[i] = LR[i + 32];
        }
        keySchedule::genRoundKey();
        for(int i = 0; i < 16; ++i) {
            for(int j = 0; j < 32; ++j) temp[j] = L[j];
            for(int j = 0; j < 32; ++j) L[j] = R[j];
            R = F::afterF(R, keySchedule::getRoundKey(i + 1));
            for(int j = 0; j < 32; ++j) R[j] = R[j]^temp[j];
        }
        for(int i = 0; i < 32; ++i) {
            RL[i] = R[i];
            RL[i + 32] = L[i];
        }
        C = IP::afterIPInv(RL);
        return C;
    }
};

int main(int argc, char* argv[]) {
    if(argc != 2 || strlen(argv[1]) != 64) {
        cout << "Illegal input\n";
    } else {
        vector<bool> P(64);
        for(int i = 0; i < 64; ++i) P[i] = argv[1][i] - '0';
        vector<bool> C = encrypt::encryption(P);
        cout << "ciphertext:";
        for(int i = 0; i < 64; ++i) cout << C[i];
        cout << "\n";
    }
    return 0;
}
