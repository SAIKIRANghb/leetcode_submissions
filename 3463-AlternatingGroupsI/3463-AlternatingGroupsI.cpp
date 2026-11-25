// Last updated: 11/25/2026, 3:39:18 PM
// class Solution {
// public:
//     int numberOfAlternatingGroups(vector<int>& colors) {
//         int n = colors.size();
//         vector<int>Start(n,0);
//         int ans = 0;
//         for(int i = 0;i<n;i++){
//             int iTh = colors[i];
//             bool flag = false;
//             int j = i;
//             int count = 0;
//             while(count <= 3-1){
//                 if(Start[j] && colors[j] == iTh){
//                     break;
//                 }
//                 if(iTh != colors[j]){
//                     flag = true;
//                     break;
//                 }
//                 count++;
//                 iTh = !iTh;
//                 j = (j+1)%n;
//             }
//             if(!flag){
//                 Start[i] = true;
//                 ans++;
//             }
//         }
//         return ans ;
//     }
// };

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int winSize = 0;
        int ans = 0;
        int k = 3;
        for(int i = 0;i<=(n - 1 + k -1);i++){
            if(colors[i % n] != colors[(i-1+n) % n]){
                winSize++;
            }else{
                winSize = 1;
            }
            if(winSize >= k)ans++;
        }
        return ans;
    }
};