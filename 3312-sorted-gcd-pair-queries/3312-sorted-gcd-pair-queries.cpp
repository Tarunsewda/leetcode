class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> cnt(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            for (int multiple = d; multiple <= mx; multiple += d) {
                cnt[d] += freq[multiple];
            }
        }

        vector<long long> exact(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {
            exact[d] = cnt[d] * (cnt[d] - 1) / 2;

            for (int multiple = 2 * d; multiple <= mx; multiple += d) {
                exact[d] -= exact[multiple];
            }
        }

        vector<long long> prefix(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            prefix[d] = prefix[d - 1] + exact[d];
        }

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(prefix.begin(), prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};