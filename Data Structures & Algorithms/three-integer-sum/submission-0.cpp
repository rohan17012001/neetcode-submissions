class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // unordered_set<vector<int>> s;
        // sort(nums.begin(), nums.end());
        // int n=nums.size();
        // for(int i=0; i<n-2; i++){
        //     int j=i+1, k=n-1;
        //     while(j<k){
        //         if(nums[i]+nums[j]+nums[k]==0){
        //             s.insert({nums[i], nums[j], nums[k]});
        //         }
        //     }
        // }
        // vector<vector<int>> ans;
        // for(auto i: s){
        //     ans.push_back(i);
        // }
        // return ans;
        int n=nums.size();
        vector<vector<int>> ans;
        // vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            if (i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1, k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                else if(nums[i]+nums[j]+nums[k]>0) k--;
                else j++;
            }
        }
        return ans;
    }
};
