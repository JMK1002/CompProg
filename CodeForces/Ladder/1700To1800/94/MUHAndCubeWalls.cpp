//
// Created by JMKov on 7/13/2023.
//
#include <iostream>
using namespace std;

// C++ program for implementation of KMP pattern searching
// algorithm

int ans = 0;

void computeLPSArray(const int* pat, int M, int* lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(int* pat, int* txt, int N, int M)
{

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
//            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
            ans++;
        }

            // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(const int* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    int s[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> s[i];
    int da[n - 1];
    int sa[m - 1];
    for (int i = 0; i < n - 1; i++) da[i] = a[i + 1] - a[i];
    for (int i = 0; i < m - 1; i++) sa[i] = s[i + 1] - s[i];
    if (m == 1) {
        cout << n << endl;
        return 0;
    }
//    for (int i : da) cout << i << " ";
//    cout << endl;
//    for (int i : sa) cout << i << " ";
//    cout << endl;
    KMPSearch(sa, da, n - 1, m - 1);
    cout << ans << endl;
    return 0;
}