//
// Created by JMKov on 5/18/2024.
//
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    bool orgs = (a <= e && e <= b);
    bool borgs = (c <= e && e <= d);
    if (orgs && borgs) cout << "Both Orgs and Borgs" << endl;
    if (!orgs && borgs) cout << "Borgs only" << endl;
    if (orgs && !borgs) cout << "Orgs only" << endl;
    if (!orgs && !borgs) cout << "Neither Orgs nor Borgs" << endl;
    return 0;
}