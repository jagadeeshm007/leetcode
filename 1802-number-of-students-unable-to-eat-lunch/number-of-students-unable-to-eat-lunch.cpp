#include <vector>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> frq(2,0);
        for (auto it : students)
            frq[it]++;
        int r = sandwiches.size();
        for (auto it : sandwiches) {
            if (frq[it]==0) break;
            if (r==0) break;
            frq[it]--;
            r--;
        }
        return r;
    }
};