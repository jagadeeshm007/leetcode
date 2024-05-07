class Solution {
public:
    string simplifyPath(string path) {
        string s="",p;
        stack<string> st;

        for(int i=0;i<path.length();i++) {
           if(path[i]!='/')
                p+=path[i];
           else if(p!=""){
                if(p!="."){
                    if(p==".." && !st.empty()) st.pop();
                    else if(p!="..") st.push(p);
                }
                p="";
           }
        }

        if(p!="" && p!="." && p!="..") st.push(p);
        else if(p==".." && !st.empty()) st.pop();

        if(st.empty()) s+="/";

        while(!st.empty()) {
            s="/"+st.top()+s; 
            st.pop();
        }
        
        return s;
    }
};