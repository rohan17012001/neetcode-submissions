class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v;
        for(int i=0; i<=n; i++){
            uint32_t x=(uint32_t)i;
            v.push_back(popcount(x));
        }
        return v;
    }
};
