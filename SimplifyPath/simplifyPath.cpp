class Solution {
public:
    string simplifyPath(string path) {
        string r;
        if(path.size()==0) return r;
        path.insert(path.begin(), '/');
        stack<string> st;
        int i=0;
        while(i<path.size()) {
            if(path[i]=='/') {
                while(i<path.size() && path[i]=='/') i++;
                if(i==path.size()) break;
                if(path.size()-i==2 && path.substr(i,2)=="..") {
                    if(!st.empty()) st.pop();
                    i+=3;
                } else if(path.substr(i,3)=="../") {
                    if(!st.empty()) st.pop();
                    i+=2;
                } else if(path.size()-i==1 && path[i]=='.') {
                    i+=2;
                } else if(path.substr(i,2)=="./") {
                    i+=1;
                } else {
                    string f;
                    while(i<path.size() && path[i]!='/') {f+=path[i];++i;}
                    st.push(f);
                }
            }
        }
        while(!st.empty()) {
            string tmp="/"+st.top();
            r.insert(r.begin(), tmp.begin(), tmp.end());
            st.pop();
        }
        if(r.empty()) r+="/";
        return r;
    }
};
