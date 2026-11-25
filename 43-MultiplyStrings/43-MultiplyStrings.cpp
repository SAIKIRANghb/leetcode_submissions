// Last updated: 11/25/2026, 3:49:53 PM
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        int j = n2 - 1;
        int pf = 0;
        string res(n1 + n2, '0');
        
        while (j >= 0) {
            int i = n1 - 1;
            int carry = 0;
            int k = n1 + n2 - 1 - pf;
            int jval = num2[j] - '0';
            
            while (i >= 0 || carry != 0) {
                int ival = i >= 0 ? num1[i] - '0' : 0;
                int ans = ival * jval + carry + res[k] - '0';
                int result = ans % 10;
                res[k] = result + '0';
                carry = ans / 10;
                k--;
                i--;
            }
            
            pf++;
            j--;
        }
        
        int start = 0;
        while (start < res.size() && res[start] == '0') {
            start++;
        }
        if (start == res.size()) {
            return "0";
        }
        
        return res.substr(start); 
    }
};

