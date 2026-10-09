#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    map<string, string> names;
    for (int i = 0; i < x; i++) {
        string tag, ip;
        cin >> tag >> ip;
        names.insert(names.end(), pair<string, string>(ip, tag));
    }
    for (int i = 0; i < y; i++) {
        string tag, ip;
        cin >> tag >> ip;
        ip = ip.substr(0, ip.size() - 1);
        cout << tag << " " << ip << "; #" << names[ip] << endl;
    }

    return 0;
}