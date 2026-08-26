class Solution {
public:
    void solve(int i, int sum, vector<int>& v, vector<vector<int>>& ans, vector<int>& nums, int target){
        if(sum==target){
            // sort(v.begin(), v.end());
            // if(find(ans.begin(), ans.end(), v)==ans.end()) 
            ans.push_back(v);
            return;
        }
        if(i>=nums.size() || sum>target) return;
        // if(i==n) return;
        v.push_back(nums[i]);
        solve(i, sum+nums[i], v, ans, nums, target);
        v.pop_back();
        solve(i+1, sum, v, ans, nums, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        // int sum=0;
        vector<vector<int>> ans;
        solve(0, 0, v, ans, nums, target);
        return ans;
    }
};
