// Last updated: 11/25/2026, 3:46:52 PM
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>umap;
        priority_queue<int>pq;
        queue<pair<int,int>>q;
        int time = 0;
        for(auto task : tasks){
            umap[task]++;
        }   
        for(auto [key,value] : umap){
            pq.push(value);
        }
        while(!pq.empty() || !q.empty()){
            if(!q.empty() && q.front().second == time){
                int remain = q.front().first;
                q.pop();
                pq.push(remain);
            }
            if(!pq.empty()){
                int top = pq.top();
                pq.pop();
                if(top > 1)q.push({top - 1,time + n + 1});
            }
            time++;
        }
        return time;
    }
};