#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    long long t;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        long long n, q;
        std::cin >> n >> q;
        std::vector<long long> nums(n);
        for (long long i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }
        std::vector<long long> pre(n + 1, 0LL);
        std::partial_sum(nums.begin(), nums.end(), pre.begin() + 1);
        std::vector<long long> pre_xor(n + 1, 0LL);
        std::vector<long long> left(n), right(n);
        long long ind = -1LL;
        for (long long i = 0; i < n; ++i) {
            left[i] = i;
            pre_xor[i + 1] = pre_xor[i] ^ nums[i];
            if (ind != -1) {
                left[i] = ind;
            }
            if (nums[i]) {
                ind = i;
            }
        }

        ind = -1;
        for (long long i = n - 1; i >= 0; --i) {

            right[i] =i;
            if (ind != -1) {
                right[i] = ind;
            }
            if (nums[i]) {
                ind = i;
            }
        }

        while (q--) {
            long long ll, rr;
            std::cin >> ll >> rr;
            --ll;
            --rr;
            std::vector<long long> lst = { ll };
            while (right[lst.back()] != lst.back() && right[lst.back()] <= rr && lst.size() <= 32) {
                lst.push_back(right[lst.back()]);
            }

            std::vector<long long> lst2 = { rr };
            while (left[lst2.back()] != lst2.back() && left[lst2.back()] >= ll && lst2.size() <= 32) {
                lst2.push_back(left[lst2.back()]);
            }

            std::vector<long long> ans = {0LL, ll + 1, ll + 1 };
            for (long long i : lst) {

                for (long long j : lst2) {
                    if (i <= j) {
                        long long cur = pre[j + 1] - pre[i] - (pre_xor[j + 1] ^ pre_xor[i]);
                        if (ans[0] < cur || (ans[0] == cur && ans[2] - ans[1] > j - i)) {
                            ans = { cur, i + 1, j + 1 };
                        }
                    }
                }
            }
            std::cout << ans[1] << " " << ans[2] << std::endl;
        }
    }

    return 0;
}
