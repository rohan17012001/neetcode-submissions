class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0;
        int ans=0;
        unordered_map<char, int> m;
        for(int i=0; i<n; i++){
            while(m[s[i]]>0){
                m[s[l]]--;
                l++;
            }
            m[s[i]]++;
            ans=max(ans, i-l+1);
        }
        return ans;
    }
};
