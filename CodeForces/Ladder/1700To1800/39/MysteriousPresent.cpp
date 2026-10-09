//
// Created by JMKov on 6/22/2023.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> arr[5010];
int dp[5010];
int cont[5010];

bool strictComp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first && a.second < b.second;
}

bool indiciesComp(int a, int b) {
    return arr[a] < arr[b];
}

int main() {
    int n;
    pair<int, int> card;
    cin >> n >> card.first >> card.second;
    int indicies[n];
    for (int i = 0; i < n; i++) {
        indicies[i] = i;
        cin >> arr[i].first >> arr[i].second;
    }
    sort(indicies, indicies + n, indiciesComp);
    sort(arr, arr + n);
//    for (int i = 0; i < n; i++) cout << arr[i].first << " " << arr[i].second << endl;
//    cout << endl;
    for (int & i : dp) i = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] != -1 && strictComp(arr[j], arr[i]) && cont[i] < cont[j] + 1) {
                dp[i] = j;
                cont[i] = cont[j] + 1;
            }
        }
        if (dp[i] == -1 && strictComp(card, arr[i])) {
            dp[i] = i;
            cont[i] = 1;
        }
    }

    int mx = 0;
    int index = 0;
    for (int i = 0; i < n; i++) {
//        cout << dp[i] << " " << cont[i] << endl;
        if (cont[i] > mx) {
            mx = cont[i];
            index = i;
        }
    }
    cout << cont[index] << endl;
    if (cont[index] == 0) return 0;
    vector<int> ans(cont[index]);
    int count = cont[index] - 1;
    int x = index;
    while (x != dp[x]) {
        ans[count] = indicies[x] + 1;
        x = dp[x];
        count--;
    }
    ans[0] = indicies[x] + 1;
    for (int i : ans) cout << i << " ";
    cout << endl;
//    cout << count << endl;
//    for (int i : ans) cout << i + 1 << " ";
    cout << endl;
    return 0;
}
//7 3 3
//1 7
//2 6
//3 2
//8 3
//4 4
//9 2
//1 8

//7 0 0
//1 5
//1 2
//2 6
//3 8
//4 4
//4 4
//5 10