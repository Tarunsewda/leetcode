class Solution {
private:
    vector<int> prefixSum;
    vector<int> dp;

    int solve(const vector<int>& stoneValue, int idx){
        int n = stoneValue.size();
        if(idx >= n) return 0;

        if(dp[idx] != -1e9) return dp[idx];
        int ans = -1e9;

        int take1stStone = (prefixSum[idx+1] - prefixSum[idx]) - solve(stoneValue, idx+1);
        ans = max(ans, take1stStone);    

        if(idx+1 < n){
            int take2NdStone = (prefixSum[idx+2] - prefixSum[idx]) - solve(stoneValue, idx+2);
            ans = max(ans, take2NdStone);
        }

        if(idx+2 < n){
            int take3RdStone = (prefixSum[idx+3] - prefixSum[idx]) - solve(stoneValue, idx+3);
            ans = max(ans, take3RdStone);
        }

        return dp[idx] = ans;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        prefixSum.assign(n+1, 0);
        for(int i=1; i<=n; i++) prefixSum[i] = prefixSum[i-1] + stoneValue[i-1];

        dp.assign(n, -1e9);

        int ans = solve(stoneValue, 0);

        if(ans == 0) return "Tie";
        else if(ans < 0) return "Bob";
        else return "Alice";
    }
};