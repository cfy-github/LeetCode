class Solution {
public:
    int reverse(int x) {
        int l=x%10;
        int h=x/10;
        int ret=0;
        while(h!=0) {
            ret=ret*10+l;
            l=h%10;
            h=h/10;
        }
        return ret*10+l;
    }
};
