class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int j=0;
        for(int i=n-1;i>=0;i--){
            if( j++ >= citations[i]) return j-1;
        }

        return j;
    }
};