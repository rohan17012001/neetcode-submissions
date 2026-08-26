class Solution {
    int getascii(char ch){
        if(ch>=65 && ch<=90) return ch;
        else if(ch>=97 && ch<=122) return ch-32;
        return -1;
    }
    int isdigit(char ch){
        if(ch>=48 && ch<=57) return ch;
        return -1;
    }
public:
    bool isPalindrome(string s) {
        // string s;
        string t;
        for(auto i: s){
            if(isdigit(i)!=-1) t+=i;
            else if(getascii(i)!=-1) t+=getascii(i);
        }
        int i=0, j=t.length()-1;
        while(i<j){
            if(t[i++]!=t[j--]) return false;
        }
        return true;
    }
};
