class Solution {
public:
    bool isNumber(const char *s) {
        int state=0;
        if(!*s) return false;
        
        while(isspace(*s)) s++;
        if(*s=='-'||*s=='+') s++;
        while(isdigit(*s)) s++;
        
        if(!*s) return isdigit(*(s-1));
        if(isdigit(*(s-1))) {
            while(isspace(*s)) s++;
            if(isspace(*(s-1))) return *s=='\0';
        }

        if(*s=='.') {
            if(isdigit(*(s-1))) {
                if(*(s+1)=='\0') return true;
                if(*(s+1)==' ') {
                    const char *p=s+1;
                    while(isspace(*p)) p++;
                    if(*p) return false;
                    else return true;
                }
            }
            s++;
            if(isdigit(*s)) {
                while(isdigit(*s)) s++;
                while(isspace(*s)) s++;
                if(!*s) return true;
                else if(isspace(*(s-1))) return false;
            } else {
                if(*s!='e' && *s!='E') return false;
            }
        }
        
        if(isdigit(*(s-1)) || (*(s-1)=='.' && isdigit(*(s-2)))) state=2;
        
        if(*s=='E'||*s=='e') {
            if(state!=2) return false;
            s++;
            if(*s=='+'||*s=='-') s++;
            if(!isdigit(*s)) return false;
            while(isdigit(*s)) s++;
            while(isspace(*s)) s++;
            if(!*s) return true;
        }
        
        return false;
    }
};
