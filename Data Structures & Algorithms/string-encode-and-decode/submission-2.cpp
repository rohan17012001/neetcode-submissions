class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        int n=strs.size();
        for(int i=0; i<n; i++){
            int l=strs[i].size();
            // ans+='#';
            ans+=to_string(l);
            ans+='#';
            ans+=strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        // stringstream ss(s);
        // string temp;
        // while(getline(ss, temp, '~')){
        //     ans.push_back(temp);
        // }
        int i=0;
        int n=s.length();
        while(i<n){
            int hashPos = s.find('#', i);
            int l = stoi(s.substr(i, hashPos-i));
            string temp = s.substr(hashPos + 1, l);
            ans.push_back(temp);
            i = hashPos + 1 + l;
        }
        return ans;
    }
};
