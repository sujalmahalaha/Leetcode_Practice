class Solution {
public:
    bool checkPowersOfThree(int n) {
       int p = 0;
       while(pow(3,p)<=n){
        p++;
       }
       while(n>0){
        if(pow(3,p)<=n){
            n = n-pow(3,p);
        }
         if(pow(3,p)<=n){
           return false;
        }
        p--;
       }
       return true ;
        
    }
};