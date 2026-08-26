class Solution {
public:
    static bool check(auto& i, auto& j){
        return i.second>j.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> q;
        for(auto i: nums){
            m[i]++;
            // q.push({m[i], i});
        }
        for(auto i: m){
            q.push({i.second, i.first});
        }
        // sort(m.begin(), m.end(), check);
        vector<int> ans;
        while(k--){
            auto i=q.top();
            q.pop();
            ans.push_back(i.second);
            // k--;
            // if(k==0) break;
        }
        return ans;
    }
};
