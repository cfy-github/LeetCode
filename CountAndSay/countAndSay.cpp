class Solution {
public:
    string countAndSay(int n) {
        string str;
        if(n==0) return str;
        str="1";
        for(int i=1;i<n;i++) {
            str=say(str);
        }
        return str;
    }
    inline string say(string &str) {
        stringstream ss;
        for(auto i=str.begin();i!=str.end();) {
            auto j=find_if(i,str.end(),bind1st(not_equal_to<char>(), *i));
            ss<<distance(i,j)<<*i;
            i=j;
        }
        return ss.str();
    }
};
