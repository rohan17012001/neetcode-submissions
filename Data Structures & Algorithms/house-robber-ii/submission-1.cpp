class Solution {
public:
    int solve(vector<int>& nums, int start, int end){
        if(start==end) return nums[start];
        int n=nums.size();
        vector<int> dp(end-start, 0);
        dp[0]=nums[start];
        if(end-start>1) dp[1]=max(nums[start], nums[start+1]);
        for(int i=start+2; i<end; i++){
            int take=nums[i]+dp[i-start-2];
            int nottake=dp[i-start-1];
            dp[i-start]=max(take, nottake);
        }
        return dp[end-start-1];
    }
    int rob(vector<int>& nums) {
        int a=solve(nums, 0, nums.size()-1);
        int b=0;
        if(nums.size()>1)
        b=solve(nums, 1, nums.size());
        // reverse(nums.begin(), nums.end());
        // int b=solve(nums);
        return max(a, b);
    }
};
