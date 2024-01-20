static const auto _ = [](){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    return 0;
}();

class Solution {
public:
    int minPartitions(string n) {
        int m = INT_MIN;
        for(int i = 0 ; i < n.length() ; i++ ) {
            m = max(m,(int)n[i]-48);
        }

        return m;
    }
};