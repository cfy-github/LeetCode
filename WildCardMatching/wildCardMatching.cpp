class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        char ch='\0';
        const char *s_last=&ch, *last=&ch;
        
        while(*s && (*p || *last)) {
            //if(!*s && !*p) return true;
            //if(!*s) return false;
            //if(!*p && !*last) return false;
            if(!*p && *last) {
                p=last+1;
                s=s_last+1;
                s_last=s;
                continue;
            }else if(*p=='*') {
                //skip redundent *'s
                while(*(p+1)=='*') p++;
                last=p;
                s_last=s;
                p++;
                continue;
            }else if(*p!='?' && *p!=*s) {
                if(*last) {
                    p=last+1;
                    s=s_last+1;
                    s_last=s;
                    continue;
                } else return false;
            }
            p++;
            s++;
        }
        
        if(!*s && *p=='*') {
            while(*(p+1)=='*') p++;
            if(!*(p+1)) return true;
        }
        return *s==*p;
    }
};
