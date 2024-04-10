class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int> ans(n,0);
        sort(deck.begin(),deck.end());
        deque<int> dq;
        for(int i=0;i<n;i++) dq.push_back(i);

        for(int i=0;i<n;i++){
            int id = dq.front();
            dq.pop_front();
            ans[id] = deck[i];
            if(!dq.empty()){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        return ans;
    }
};