// Last updated: 11/25/2026, 3:50:18 PM
class Solution {
public:
    string intToRoman(int num) {
        int n = num;
        int placeVal = 1;

        string ans;
        while (n > 0) {
            if (placeVal == 1) {
                if (n % 10 == 1) {
                    ans += 'I';
                } else if (n % 10 == 2) {
                    ans += "II";
                } else if (n % 10 == 3) {
                    ans += "III";
                } else if (n % 10 == 4) {
                    ans += "IV";
                } else if (n % 10 == 5) {
                    ans += 'V';
                } else if (n % 10 == 6) {
                    ans += "VI";
                } else if (n % 10 == 7) {
                    ans += "VII";
                } else if (n % 10 == 8) {
                    ans += "VIII";
                } else if (n % 10 == 9) {
                    ans += "IX";
                }
            } else if (placeVal == 2) {
                    if (n % 10 == 1) {
                        ans = 'X' + ans;
                    } else if (n % 10 == 2) {
                        ans = "XX" + ans;
                    } else if (n % 10 == 3) {
                        ans = "XXX" + ans;
                    } else if (n % 10 == 4) {
                        ans = "XL" + ans;
                    } else if (n % 10 == 5) {
                        ans = 'L' + ans;
                    } else if (n % 10 == 6) {
                        ans = "LX" + ans;
                    } else if (n % 10 == 7) {
                        ans = "LXX" + ans;
                    } else if (n % 10 == 8) {
                        ans = "LXXX" + ans;
                    } else if (n % 10 == 9) {
                        ans = "XC" + ans;
                    } 
                } else if (placeVal == 3) {
                    if (n % 10 == 1) {
                        ans = 'C' + ans;
                    } else if (n % 10 == 2) {
                        ans = "CC" + ans;
                    } else if (n % 10 == 3) {
                        ans = "CCC" + ans;
                    } else if (n % 10 == 4) {
                        ans = "CD" + ans;
                    } else if (n % 10 == 5) {
                        ans = 'D' + ans;
                    } else if (n % 10 == 6) {
                        ans = "DC" + ans;
                    } else if (n % 10 == 7) {
                        ans = "DCC" + ans;
                    } else if (n % 10 == 8) {
                        ans = "DCCC" + ans;
                    } else if (n % 10 == 9) {
                        ans = "CM" + ans;
                    }   
                } else if (placeVal == 4) {
                    int n1 = n;
                    while(n1 > 0){
                        ans = 'M' + ans;
                        n1--;
                    }
                }
                placeVal++;
                n = n / 10;
            }
            return ans;
        }
    };