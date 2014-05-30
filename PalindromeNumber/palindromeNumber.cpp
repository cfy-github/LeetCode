class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int tmp=x, div=1;
        while(tmp/=10) div*=10;
        while(x>=10) {
            if(x/div!=x%10) return false;
            x=(x%div)/10;
            div/=100;
        }
        if(div>1&&x!=0) return false;
        return true;
    }
};
