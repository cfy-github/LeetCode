class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> r;
        int n=words.size();
        
        vector<string> v;
        int cnt=0, len=0;
        for(int i=0;i<n;++i) {
            int tmp_len=len+words[i].size();
            int pad_len=L-tmp_len;
            
            //One word one line:
            if(v.empty() && pad_len>=0) {
                v.push_back(words[i]);
                len=tmp_len;
                cnt=0;
                continue;
            }
            
            if(pad_len>=cnt+1) {
                v.push_back(words[i]);
                cnt++;
                len=tmp_len;
            } else {
                pad_len=L-len;
                int avg=(cnt==0)?0:(pad_len/cnt);
                int left=(cnt==0)?0:(pad_len%cnt);
                string str(v[0]);
                for(int s=1,j=0;s<v.size();++s, ++j) {
                    int num_space=j<left?avg+1:avg;
                    for(int k=0;k<num_space;++k) str+=" ";
                    str+=v[s];
                }
                if(v.size()==1) {for(int k=0;k<pad_len;++k) str+=" ";}
                r.push_back(str);
                
                v.clear();
                v.push_back(words[i]);
                cnt=0;
                len=words[i].size();
            }
        }
        if(!v.empty()) {
            string str(v[0]);
            for(int i=1;i<v.size();++i) {
                str+=(" "+v[i]);
            }
            int pad_len=L-cnt-len;
            for(int k=0;k<pad_len;++k) str+=" ";
            r.push_back(str);
        }
        return r;
    }
};
