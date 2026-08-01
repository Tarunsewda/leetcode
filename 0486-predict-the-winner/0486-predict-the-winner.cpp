class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        return getNetScore(nums, 0, nums.size() - 1) >= 0;
    }

private:
    int getNetScore(vector<int>& nums, int i, int j) {
        if (i == j)
            return nums[i];

        int pickLeft = nums[i] - getNetScore(nums, i + 1, j);
        int pickRight = nums[j] - getNetScore(nums, i, j - 1);

        return max(pickLeft, pickRight);
    }
};