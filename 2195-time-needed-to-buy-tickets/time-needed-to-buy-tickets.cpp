class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int tt=0;
        for(int i=0;i<=100;i++){
        for(int j=0;j<tickets.size();j++){
            if(tickets[k] == 0) return tt;
            else{
                if(tickets[j] == 0) continue;
                else {
                    tickets[j]--;
                    tt++;
                }
            }
            }
        }
        return tt;
      
    }
};