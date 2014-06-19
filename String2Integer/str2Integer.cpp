class Solution {
public:
    int atoi(const char *str) {
        const char *pc=str;
        while(*pc && isspace(*pc)) pc++;
        if(!*pc) return 0;
        
        bool sgn=true;
        if(*pc=='-') {
            sgn=false;
            pc++;
        } else if(*pc=='+') {
            pc++;
        }
        
        long long r=0;
        while(*pc && isdigit(*pc)) {
            r*=10;
            r+=(*pc-'0');
            pc++;
        }
        r=sgn?r:-r;
        if(r>INT_MAX) return INT_MAX;
        if(r<INT_MIN) return INT_MIN;
        return r;
    }
};
