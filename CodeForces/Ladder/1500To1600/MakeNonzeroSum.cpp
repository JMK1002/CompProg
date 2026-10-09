#include <algorithm>
#include <bitset>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,N) FOR(i,0,N)
#define FORD(i,b,a) for (int i = (int)(b)-1; i >= a; --i)

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define st first
#define nd second
#define pb push_back

const int MOD = 1000000007;

int A[222222];
void scase() {
    int N;
    scanf("%d", &N);
    REP(i,N) scanf("%d", &A[i]);

    int sum = 0;
    REP(i,N) sum += A[i];
    if (sum % 2) {
        printf("-1\n");
        return;
    }

    vector<PII> intervals;
    vector<int> ends;

    int c = 0;
    while (c < N) {
        if (c < (N-1) && sum < 0 && A[c+1] < 0) {
            sum += 2;
            intervals.pb({c, c+1});
            c += 2;
        } else if (c < (N-1) && sum > 0 && A[c+1] > 0) {
            sum -= 2;
            intervals.pb({c, c+1});
            c += 2;
        } else {
            intervals.pb({c, c});
            c += 1;
        }
    }

    if (sum != 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", intervals.size());
    for (auto i: intervals) printf("%d %d\n", i.st + 1, i.nd + 1);
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) scase();
}
