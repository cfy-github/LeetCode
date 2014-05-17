class Solution {
public:
    string intToRoman(int num) {
       int radix[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
       string d[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
       string r;
       int msb;
       for(int i=0;i<13;i++) {
           msb=num/radix[i];
           num%=radix[i];
           for(int j=0;j<msb;j++) r+=d[i];
       }
       return r;
    }
};
