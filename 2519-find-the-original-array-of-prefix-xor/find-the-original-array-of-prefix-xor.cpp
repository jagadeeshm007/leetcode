class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int post = 0,pre = 0;
        vector<int> v;
        for(auto i : pref) {
            post ^=pre;
            pre = post;
            post^= i;
            v.push_back(post);
        }

        return v;
    }
};