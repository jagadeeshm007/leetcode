class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> dp = {0};
        int result = 0;
        
        for (auto s : arr) {

            int a = 0, value = 0;
            for (auto c : s) {

                value = value | (a & (1 << (c - 'a')));
                a = a | (1 << (c - 'a'));
            }

            if (value > 0) continue;

            for (int i = dp.size() - 1 ; i >= 0; i--) {

                if ((dp[i] & a) > 0) continue;
                dp.push_back(dp[i] | a);
                result = max(result, __builtin_popcount(dp[i] | a));
            }
        }
        
        return result;
    }
};