// Last updated: 11/25/2026, 3:43:50 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue<pair<int,int>>maxHp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHp;
        int i = 0,j = 0;
        int maxLen = 0;
        while(j<n){
            maxHp.push({nums[j],j});
            minHp.push({nums[j],j});
            int diff = maxHp.top().first - minHp.top().first;
            while(i<j && diff > limit){
                i = min(maxHp.top().second,minHp.top().second) + 1;
                while(maxHp.top().second < i)maxHp.pop();
                while(minHp.top().second < i)minHp.pop();
                diff = maxHp.top().first - minHp.top().first;
            }
            maxLen = max(maxLen,j - i + 1);
            j++;
        }
        return maxLen;
    }
};










/*
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0,j = 0,maxLen = 0;
        priority_queue<pair<int,int>>maxHp;
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> minHp;
        while(j<n){
            maxHp.push({nums[j],j});
            minHp.push({nums[j],j});
            int diff = maxHp.top().first - minHp.top().first;
            while(i<j && diff > limit){
                i = min(maxHp.top().second,minHp.top().second) + 1;
                while(maxHp.top().second < i)maxHp.pop();
                while(minHp.top().second < i)minHp.pop();
                diff = maxHp.top().first - minHp.top().first;
            }
            maxLen = max(maxLen , j - i+1);
            j++;
        }
        return maxLen;
    }
};
*/