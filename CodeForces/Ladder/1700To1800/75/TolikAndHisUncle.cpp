#include <bits/stdc++.h>

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0, p = n * m - 1, d = 1; p >= 0; i += d * p, p--, d *= -1)
        printf("%d %d\n", i/m + 1, i%m + 1);
}

