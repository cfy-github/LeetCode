class Solution {
public:
    string addBinary(string a, string b) {
        int na=a.size(), nb=b.size();
        string r;
        int n=na<nb?na:nb;
        bool carry=false;
        int i=0;
        for(;n-1-i>=0;i++) {
            if(carry) {
                if(b[nb-1-i]!=a[na-1-i]) {
                    r.insert(r.begin(),'0');
                    carry=true;
                }
                else if(a[na-1-i]=='1') {
                    r.insert(r.begin(),'1');
                    carry=true;
                } else {
                    r.insert(r.begin(),'1');
                    carry=false;
                }
            } else {
                if(b[nb-1-i]!=a[na-1-i]) {
                    r.insert(r.begin(),'1');
                    carry=false;
                } else if(a[na-1-i]=='1') {
                    r.insert(r.begin(),'0');
                    carry=true;
                } else {
                    r.insert(r.begin(),'0');
                    carry=false;
                }
            }
        }
        while(nb-1-i>=0) {
            bool t=(b[nb-1-i]=='1');
            r.insert(r.begin(),(carry^t)?'1':'0');
            carry=(carry&&t);
            i++;
        }
        while(na-1-i>=0) {
            bool t=(a[na-1-i]=='1');
            r.insert(r.begin(),(carry^t)?'1':'0');
            carry=(carry&&t);
            i++;
        }
        if(carry) r.insert(r.begin(), '1');
        return r;
    }
};
