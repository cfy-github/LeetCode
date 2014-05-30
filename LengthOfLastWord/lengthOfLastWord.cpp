class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len=0;
        bool flag=false;
        while(*s) {
            if(*s!=' ') {
                if(!flag) len++;
                else {
                    len=1;
                    flag=false;
                }
            } else {
                flag=true;
            } 
            s++;
        }
        return len;
    }
};
