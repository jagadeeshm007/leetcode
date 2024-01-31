class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s;
        vector<int> re(t.size(),0);
        for(int i=0;i<t.size();i++) {
            while(!s.empty() && t[s.top()] < t[i]){
                int k = s.top();
                re[k] = i-k;
                s.pop();
            }

            s.push(i);
        }

        return re;
    }
};