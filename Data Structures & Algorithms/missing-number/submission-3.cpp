class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n=nums.size();
        // int s=(n*(n+1)/2);
        // int sum=0;
        // for(auto i: nums){
        //     sum+=i;
        // }
        // // if(sum==(n*(n+1)/2)) return 0;
        // return s-sum;
        int n=nums.size();
        int s=0;
        for(int i=0; i<=n; i++) s^=i;
        for(auto i: nums) s^=i;
        return s;
    }
};
