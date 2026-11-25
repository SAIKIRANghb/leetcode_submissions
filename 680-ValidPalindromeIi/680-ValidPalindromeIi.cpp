// Last updated: 11/25/2026, 3:46:35 PM
class Solution {
public:

   bool palindrome(string s, int i,int j){
    while(i<=j){
        if(s[i] == s[j]){
            i++;j--;
        }else{
            return false;
        }
    }
    return true;
   }
    
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0 , j = n-1;
        while(i <= j){
            if(s[i] == s[j]){
                i++;
                j--;
            }else{
                if(palindrome(s,i+1,j) || palindrome(s,i,j-1)){
                    return true;
                }else{
                    return false;
                }
            }
        }
        return palindrome(s,0,n-1);
    }
};