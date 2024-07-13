class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector< vector<int>> v;
        for(int i=0;i<n;i++) {
            if(directions[i] == 'R') v.push_back({positions[i],healths[i],0,i});
            else v.push_back({positions[i],healths[i],1,i});
        }
        sort(v.begin(),v.end());
        int i=0;
        stack<vector<int>> st;
        while(i<v.size()) {
            if(st.empty()){
                st.push(v[i]);
            }
            else{
                if(st.top()[2]==0 && v[i][2]==1){
                    if(st.top()[1] > v[i][1]){
                        st.top()[1]--;
                    }
                    else if(st.top()[1] <= v[i][1]){
                        while(!st.empty() && st.top()[2]==0 && v[i][2]==1 && st.top()[1] < v[i][1]){
                            st.pop();
                            v[i][1]--;
                        }
                        if(!st.empty() && st.top()[2]==0 && v[i][2]==1 && st.top()[1] > v[i][1]){
                            st.top()[1]--;
                        }
                        else if(!st.empty() && st.top()[2]==0 && v[i][2]==1 && st.top()[1] == v[i][1]){
                            st.pop();
                        }
                        else {
                            st.push(v[i]);
                        }
                    }
                }
                else{
                    st.push(v[i]);
                }
            }
            i++;
        }
        vector<vector<int>> tmp;
        vector<int> ans;
        while(!st.empty()){
            tmp.push_back({st.top()[3],st.top()[1]});
            st.pop();
        }
        sort(begin(tmp),end(tmp));
        for(auto it : tmp) ans.push_back(it[1]);
        return ans;
    }
};