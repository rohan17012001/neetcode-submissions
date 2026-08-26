class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int ltor=1, rtol=1;
        for(int i=0; i<n; i++){
            if(ltor==0) ltor=1;
            if(rtol==0) rtol=1;
            ltor*=nums[i];
            int j=n-i-1;
            rtol*=nums[j];
            ans=max(ans, max(ltor, rtol));
        }
        return ans;
    }
};
