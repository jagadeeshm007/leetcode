#define all(c) c.begin(), c.end()
class Solution {
public:
    vector<int> v;

    void update(int start, int end, int idx, int pos) {
        if (start == end) {
            v[idx]++;
            return;
        }
        int mid = start + (end - start) / 2;
        if (pos <= mid) update(start, mid, 2 * idx + 1, pos);
        else update(mid + 1, end, 2 * idx + 2, pos);
        v[idx] = v[2 * idx + 1] + v[2 * idx + 2];
    }

    int query(int start, int end, int l, int r, int idx) {
        if (r < start || l > end) return 0;
        if (l <= start && end <= r) return v[idx];
        int mid = start + (end - start) / 2;
        return query(start, mid, l, r, 2 * idx + 1) + query(mid + 1, end, l, r, 2 * idx + 2);
    }

    vector<int> countSmaller(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n, 0);
        if (n == 0) return ans;
        const int N = 4 * (n + 1);
        v.assign(N, 0);

        vector<int> sortedNums = nums;
        sort(all(sortedNums));
        unordered_map<int, int> ranks;
        for (int i = 0; i < n; ++i) {
            ranks[sortedNums[i]] = i;
        }

        for (int i = n - 1; i >= 0; --i) {
            int rank = ranks[nums[i]];
            ans[i] = query(0, n - 1, 0, rank - 1, 0);
            update(0, n - 1, 0, rank);
        }
        return ans;
    }
};