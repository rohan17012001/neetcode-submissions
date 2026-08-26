class Solution {
public:
    int solve(string& s, int l, int r, int n){
        int count=0;
        while(l>=0 && r<n && s[l]==s[r]){
            count++;
            l--;
            r++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int ans=0;
        int n=s.length();
        for(int i=0; i<n; i++){
            ans+=solve(s, i, i, n);
            ans+=solve(s, i, i+1, n);
        }
        return ans;
    }
};
