// Last updated: 11/25/2026, 3:41:49 PM
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        while(i < n && j < n){
        if(start[i] == 'L' || start[i]=='R'){
            char search_for = start[i];
            char otherChar;
            if(search_for == 'L'){
                otherChar = 'R';
            }else otherChar = 'L';

            bool found_something = false;
            while(j < n){
                if(target[j] == otherChar)return false;
                if(target[j] == search_for){
                    found_something = true;
                    if(search_for == 'L' && j > i){
                        return false;
                    }
                    else if(search_for == 'R' && i > j){
                        return false;
                    }
                    else {j++;break;}
                }
                j++;
            }
            if(!found_something)break;
        }
            i++;
        }
        while(i < n){
            if(start[i] == 'L' || start[i] == 'R')return false;
            i++;
        }
        while(j < n){
            if(target[j] == 'L' || target[j] == 'R')return false;
            j++;
        }
        return true;
    }
};
