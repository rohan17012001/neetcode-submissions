class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans=0;
        for(auto i: s){
            if(s.find(i-1)==s.end()){
                int start=i;
                int len=1;
                while(s.find(start+1)!=s.end()){
                    start++;
                    len++;
                }
                ans=max(ans, len);
            }
        }
        return ans;
    }
};
