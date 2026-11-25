// Last updated: 11/25/2026, 3:43:35 PM
class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1)return '0';

        int length = (1<<n) - 1;

        int mid = length / 2 + 1;

        if(k == mid)return '1';

        if(k < mid)return findKthBit(n - 1,k);
        else return findKthBit(n - 1,length - k + 1) == '0' ? '1' : '0';
    }
};


/*
class Solution {
public:
    char findKthBit(int n, int k) {
        int i = 0;
        string prevInv = "1";
        string si = "0";
        while(i<n){
            string invert = "";
            // si += '1' + prevInv;
            si += '1';
            int Sn = si.size();
            for(int j = 0;j<Sn;j++){
                if(si[j] == '0'){
                    invert += "1";
                }
                else{
                    invert += "0";
                }
            }
            int Pn = prevInv.size();
            for(int j = 0;j<prevInv.size();j++){
                if(prevInv[Pn - 1 - j] == '0'){
                    si += '0';
                    invert += '1';
                }else{
                    si += '1';
                    invert += '0';
                }
            }
            prevInv = invert;
            i++;
        }
        return si[k - 1];
    }
};
*/