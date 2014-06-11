class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size(), n2=num2.size();
        if(n1==0||n2==0) return "0";
        string str;
        for(int i=0;i<n1;++i) {
            if(str.size()!=1||str[0]!='0') str+="0";
            string tmp=strMul(num1[i],num2);
            if(tmp.size()==1&&tmp[0]=='0') continue;
            str=strAdd(str, tmp);
        }
        return str;
    }
    string strAdd(string &s1, string &s2) {
        string r;
        int n1=s1.size();
        int n2=s2.size();
        int carry=0;
        int i,j;
        for(i=n1-1,j=n2-1;i>=0&&j>=0;--i,--j) {
            int sum=carry+(s1[i]-'0')+(s2[j]-'0');
            r.insert(r.begin(), sum%10+'0');
            carry=sum/10;
        }
        while(i>=0) {
            int sum=carry+(s1[i]-'0');
            r.insert(r.begin(), sum%10+'0');
            carry=sum/10;
            i--;
        }
        while(j>=0) {
            int sum=carry+(s2[j]-'0');
            r.insert(r.begin(), sum%10+'0');
            carry=sum/10;
            j--;
        }
        if(carry) r.insert(r.begin(), carry+'0');
        return r;
    }
    string strMul(char ch, string &str) {
        string r;
        int carry=0;
        int f=ch-'0';
        if(f==0) return "0";
        for(int i=str.size()-1;i>=0;--i) {
            int curr=str[i]-'0';
            int tmp=curr*f+carry;
            r.insert(r.begin(), tmp%10+'0');
            carry=tmp/10;
        }
        if(carry!=0) r.insert(r.begin(), carry+'0');
        return r;
    }
};
