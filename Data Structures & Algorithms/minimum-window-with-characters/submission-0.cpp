class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()) return "";
        int n=s.length();
        int m=t.length();
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for(auto i: t) m2[i]++;
        int start=-1;
        // string ans;
        int len=0;
        int l=0;
        int anslen=INT_MAX;
        int r=0;
        while(r<n){
            m1[s[r]]++;
            if(m2.find(s[r])!=m2.end() && m1[s[r]]<=m2[s[r]]) len++;
            if(len==m){
                while((m1[s[l]]>m2[s[l]]) || m2[s[l]]==0){
                    if(m1[s[l]]>m2[s[l]]) m1[s[l]]--;
                    l++;
                }
                int length=r-l+1;
                if(anslen>length){
                    anslen=length;
                    start=l;
                }
            }
            r++;
        }
        if(start==-1) return "";
        return s.substr(start, anslen);
    }
};
