class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int mx=0,fin=0;
        int sm=0,c=0;
        for(int i=0;i<minutes;i++){
            if(grumpy[i]){
                sm+=customers[i];
            }
            else{
                fin+=customers[i];
            }
        }
       mx=sm;
        for(int i=minutes;i<grumpy.size();i++){
            if(grumpy[i]){
                if(grumpy[i-minutes]) sm-=customers[i-minutes];
                sm+=+ customers[i];
            }
            else{
                if(grumpy[i-minutes]) sm-=customers[i-minutes];
                fin+=customers[i];
            }
            mx = max(mx,sm);
        }

        return fin+mx;
    }
};