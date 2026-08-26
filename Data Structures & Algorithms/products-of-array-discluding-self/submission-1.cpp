class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        double prod=1;
        int zero=0;
        for(auto i: nums){
            if(i==0) zero++;
            else prod*=i;
        }
        vector<int> ans;
        for(auto i: nums){
            if(i==0){
                if(zero==1) ans.push_back(prod);
                else ans.push_back(0);
            }
            else{
                if(zero>0) ans.push_back(0);
                else(ans.push_back(prod/i));
            }
        }
        return ans;
    }
};
