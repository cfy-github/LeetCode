class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!*needle) return haystack;
        char *p1=needle;
        char *p2=haystack;
        for(;*(p1+1)&&*(p2+1);++p1,++p2);
        if(*(p1+1)) return NULL;
        else {
            char *last2=p2;
            p1=needle;
            p2=haystack;
            while(*last2) {
                char *c1, *c2;
                for(c1=p1, c2=p2;c2<=last2&&*c2==*c1;++c1,++c2);
                if(c2<=last2) {last2++;p2++;}
                else return p2;
            }
        }
        return NULL;
    }
};
