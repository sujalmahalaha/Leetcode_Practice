class Solution {
public:
int Z, O , L , H;
int const m = 1e9+7;
    int solve(int l , vector<int>&t){
        if(l>H)return 0;
        if(t[l] != -1)return t[l] ;
        bool addOne = false;
        if(l>=L){
            addOne = true;
        }
        int addZero = solve(l+Z,t);
        int addOner = solve(l+O,t);
        return t[l] = (addOne + addZero +addOner)%m;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
       L = low;
       H = high ;
       O = one;
       Z = zero ;
        vector<int>t(high+1 , -1);
        return solve(0 , t);
        
    }
};