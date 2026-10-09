#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <limits>
#include <string>
#include <deque>
#include <cassert>
#include <math.h>
#include <list>




typedef long long ll;
//typedef  {int, int} p;
using namespace std;



void solve() {
    int64_t k;
    std::cin >> k;

    std::vector<int32_t> digits;
    while (k > 0) {
        digits.push_back(k % 9);
        k /= 9;
    }
    std::reverse(digits.begin(), digits.end());

    for (int32_t i = 0; i < digits.size(); i++)
        std::cout << (char)(digits[i] < 4 ? (digits[i] + '0') : (digits[i] + '1'));
    cout << "\n";



}







int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;

    while (t--)
        solve();
    return 0;

}


/*

1
9
14 19 37 59 1 4 4 98 73




*/