#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> mx(n);
        mx[0] = nums[0];
        for (int i = 1; i < n; i++) {
            mx[i] = max(mx[i - 1], nums[i]);
        }

        vector<int> prefixGcd(n);
        for (int i = 0; i < n; i++) {
            prefixGcd[i] = gcd(nums[i], mx[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            sum += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }

        return sum;
    }
};