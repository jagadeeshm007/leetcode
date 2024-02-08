class Solution {
public:
    bool isPerfectSquare(int num) {
        int n = sqrt(num);
        return n*n == num;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();