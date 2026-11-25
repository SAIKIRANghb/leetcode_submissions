// Last updated: 11/25/2026, 3:43:14 PM
class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int>res((n << 1) - 1,0);
        int used = 0;
        solve(0,res,used,n);
        return res;
    }
private:
    bool solve(int ind,vector<int>&res,int &isNumUsed,int n){
        if(ind == res.size())return true;

        if(res[ind] != 0)return solve(ind + 1,res,isNumUsed,n);

        for(int numtoPlace = n;numtoPlace >= 1;numtoPlace--){
            if(isNumUsed & (1 << numtoPlace))continue;
            isNumUsed |= (1 << numtoPlace);
            res[ind] = numtoPlace;
            if(numtoPlace == 1){
                if(solve(ind + 1,res,isNumUsed,n))return true;
            }else{
                if(ind + numtoPlace  < res.size() && res[ind + numtoPlace] == 0){
                    res[ind + numtoPlace] = numtoPlace;
                    if(solve(ind + 1,res,isNumUsed,n))return true;
                    res[ind + numtoPlace] = 0;
                }
            }
            isNumUsed &= ~(1 << numtoPlace);
            res[ind] = 0;
        }
        return false;
    }
};

// class Solution {
// public:
//     vector<int> constructDistancedSequence(int n) {
//         vector<int>res(n*2 - 1,0);
//         vector<bool>used(n + 1,false);

//         solve(0,res,used,n);
//         return res;
//     }

// private:
//     bool solve(int ind,vector<int>&res,vector<bool>&isNumUsed,int n){
//         if(ind == res.size()){
//             return true;       // if reached n --> formed a sequence return true
//         }

//         if(res[ind] != 0){
//             return solve(ind + 1,res,isNumUsed,n); // if the current ind is already filled
//         }

//         for(int numtoPlace = n;numtoPlace >= 1;numtoPlace--){  // numtoPlace is equivalent to posToPlace from current ind
//             if(isNumUsed[numtoPlace])continue;
//             isNumUsed[numtoPlace] = true;
//             res[ind] = numtoPlace;
//             //edge case : if placing 1 , then move to next index
//             if(numtoPlace == 1){
//                 if(solve(ind + 1,res,isNumUsed,n))return true;
//             }
//             //placing other numbers at two positions if valid
//             else if(ind + numtoPlace < res.size() && res[ind + numtoPlace] == 0){
//                 res[ind + numtoPlace] = numtoPlace;
//                 if(solve(ind + 1,res,isNumUsed,n))return true;
//                 //undo the placing for backtrack
//                 res[ind + numtoPlace] = 0;
//             }
//             res[ind] = 0;
//             isNumUsed[numtoPlace] = false;
//         }
//         return false;
//     }
// };

