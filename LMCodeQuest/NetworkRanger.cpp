//
// Created by JMKov on 3/21/2023.
//
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ip[4];
        int cidrVal = 32;
        char e;
        int outIp[4] = {255, 255, 255, 255};
        cin >> ip[0] >> e >> ip[1] >> e >> ip[2] >> e >> ip[3];
        for (int i = 1; i < n; i++) {
            int curIp[4];
            int idkIp[4] = { 0 };
            cin >> curIp[0] >> e >> curIp[1] >> e >> curIp[2] >> e >> curIp[3];
            //cout << curIp[0] << " " << curIp[1] << " " <<  curIp[2] << " " <<  curIp[3] << endl;
            for (int j = 31; j >= 0; j--) {
                int index = 3 - j / 8;
                int power = (int) pow(2, j % 8);
                int ipVal = ip[index];
                int curIpVal = curIp[index];
                //cout << (ip[3 - j / 8] & ((int) pow(2, j % 8))) << " " << (curIp[3 - j / 8] & ((int) pow(2, j % 8))) << endl;
                if ((ipVal & power) != (curIpVal & power)) {
                    cidrVal = min(cidrVal, 31 - j);
                    break;
                }
                else {
                    idkIp[3 - j / 8] += (ipVal & power);
                }
            }
            for (int j = 0; j < 4; j++) {
                //cout << idkIp[j] << endl;
                outIp[j] = min(idkIp[j], outIp[j]);
            }
        }
        for (int i = 0; i < 4; i++) {
            cout << outIp[i];
            if (i != 3) {
                cout << ".";
            }
        }
        cout << "/" << cidrVal;
        cout << endl;
    }
    return 0;
}