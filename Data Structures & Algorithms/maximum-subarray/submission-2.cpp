class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int ans=INT_MIN;
        int sum=0;
        int j=0;
        while(j<n){
            sum+=nums[j];
            ans=max(ans, sum);
            if(sum<0) sum=0;
            j++;
        }
        return ans;
    }
};
