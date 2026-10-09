//
// Created by JMKov on 5/30/2023.
//
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    istream::sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    vector<pair<int, int>> redistributions;
    vector<pair<int, pair<int, int>>> receipts;
    for (int i = 0; i < q; i++) {
        int id;
        cin >> id;
        if (id == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            receipts.emplace_back(i, pair<int, int>(p, x));
        }
        else {
            int x;
            cin >> x;
            while (!redistributions.empty() && redistributions[redistributions.size() - 1].second < x) {
                redistributions.erase(redistributions.begin() + (redistributions.size() - 1));
            }
            redistributions.emplace_back(i, x);
        }
    }
//    for (int i = 1; i < redistributions.size(); i++) {
//        while (i != 0 && redistributions[i].second > redistributions[i - 1].second) {
//            redistributions.erase(redistributions.begin() + (i - 1));
//            i--;
//        }
//    }
//    for (auto i : redistributions) {
//        cout << i.first << " " << i.second << endl;
//    }
//    for (auto i : receipts) {
//        cout << i.first << " " << i.second.first << " " << i.second.second << endl;
//    }
    unordered_set<int> changed;
    for (int i = 0; i < n; i++) changed.insert(i);
    int p1 = 0;
    int p2 = 0;
    while (p1 < receipts.size() || p2 < redistributions.size()) {

        if (p1 < receipts.size() && (p2 >= redistributions.size() || receipts[p1].first < redistributions[p2].first)) {
            int p = receipts[p1].second.first;
            int x = receipts[p1].second.second;
            arr[p] = x;
            changed.insert(p);
            p1++;
//            cout << "SDFDS" << endl;
        }
        else if (p2 < redistributions.size() && (p1 >= receipts.size() || receipts[p1].first > redistributions[p2].first)) {
            int x = redistributions[p2].second;
            for (int i : changed) {
                arr[i] = max(arr[i], x);
            }
            changed = *new unordered_set<int>; // might delete item that should not be deleted for checking?
            p2++;
//            cout << "banana" << endl;
        }
    }
    for (int i : arr) cout << i << " ";
    return 0;
}

//    for (int i = 0; i < x.length; i++) {
//        for (int j = 0; j < x[i].length; j++) {
//            x[i][j] = i * j;
//        }
//    }

// my teacher made me write this in my "notes" lmao
// im so on task rn
// hi if your reading this :D

// no way hes also making me write this bruh
// I just wanna do codeforces manz

// public static void main(String[] args) {
//      Scanner scan = new Scanner(System.in);
//      int r = scan.nextInt(); int c = scan.nextInt();
//      int[r][c] baldingFRFR = new int[r][c];
//      for (int i = 0; i < r; i++) {
//          for (int j = 0; j < c; j++) {
//              baldingFRFR[i][j] = i + j;
//          }
//      }
//      asdf(baldingFRFR);
//  }
//
//  public static void asdf(int[][] stillBalding) {
//      for (int i = 0; i < r; i++) {
//          for (int j = 0; j < c; j++) {
//              System.out.print(stillBalding[i][j]);
//          }
//          System.out.println("\n");
//      }
//  }
//
// 1 1
// 20
// 2 84 2 59 2 77 2 60 2 99 2 36 2 87 2 55 2 8 2 97 2 89 2 79 2 74 2 49 2 30 2 94 2 32 2 21 2 82 2 40