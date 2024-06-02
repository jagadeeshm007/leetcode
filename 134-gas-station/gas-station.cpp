class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), sm = 0, sm2 = 0, ind = 0;
        int cmp = 0;
        for (int i = 0; i < n; i++) {
            cmp += gas[i] - cost[i];
            sm += gas[i];
            sm2 += cost[i];
            if (cmp < 0) {
                cmp = 0;
                ind = i + 1;
            }
        }
        if (sm < sm2)
            return -1;

        return ind;
    }
};