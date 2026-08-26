class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        int n=s.length();
        int maxf=0;
        char ch;
        unordered_map<char, int> m;
        int l=0;
        for(int i=0; i<n; i++){
            m[s[i]]++;
            if(m[s[i]]>maxf){
                maxf=m[s[i]];
                ch=s[i];
            }
            while(i-l+1-maxf>k){
                m[s[l]]--;
                if(m[s[l]]>maxf){
                    maxf=m[s[l]];
                    ch=s[l];
                }
                l++;
            }
            ans=max(ans, i-l+1);
        }
        return ans;
    }
};
