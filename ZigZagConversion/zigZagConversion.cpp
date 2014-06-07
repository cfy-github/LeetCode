class Solution {
public:
    string convert(string s, int nRows) {
        vector<string> v(nRows);
        if(nRows==1) return s;
        int i=0,j=0;
        for(auto it=s.begin();it!=s.end();++it) {
            v[i]+=*it;
            if(j%(nRows-1)==0&&i<nRows-1) i++;
            else {i--;j++;}
        }
        string r;
        for(auto str:v) r+=str;
        return r;
    }
};
