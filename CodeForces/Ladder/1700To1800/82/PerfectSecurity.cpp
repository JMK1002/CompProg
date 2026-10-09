#include <bits/stdc++.h>
using namespace std;

int N;
int A[300100];
multiset<int> P;

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; i++) {
        int p;
        scanf("%d", &p);
        P.insert(p);
    }

    for (int i = 0; i < N; i++) {
        int a = A[i];
        int p = 0;

        for (int m = 1<<30; m > 0; m >>= 1) {
            int l = p | (a & m);
            int u = l | (m-1);

            auto lit = P.lower_bound(l);
            auto uit = P.upper_bound(u);

            if (lit != uit) {
                p |= a & m;
            }
            else {
                p |= (a^m) & m;
            }
        }

        printf("%d ", a^p);

        P.erase(P.find(p));
    }

    return 0;
}