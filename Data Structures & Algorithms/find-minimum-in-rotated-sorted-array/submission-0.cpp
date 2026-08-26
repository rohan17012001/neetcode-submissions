class Solution {
public:
    int findMin(vector<int> &nums) {
        int n= nums.size();
        int i=0, j=n-1;
        while(i<j){
            if(nums[i]<nums[j]) return nums[i];
            int k= (i+j)/2;
            if(nums[k]>nums[j]) i=k+1;
            else j=k;
        }
        return nums[i];
    }
};
