// Last updated: 11/25/2026, 3:39:41 PM
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        if (k >= n) {
            return max_element(skills.begin(), skills.end()) - skills.begin();
        }

        list<int> player{};
        
        unordered_map<int,int>umap;
        
        for(int i = 0;i<n ;i++){
            player.push_back(i);
        }
        
        while(true){
            int f = player.front();
            player.pop_front();
            int s = player.front();
            player.pop_front();
            
            if(skills[f] > skills[s]){
                player.push_front(f);
                player.push_back(s);
                umap[f]++;
                if(umap[f] >= k){
                    return f;
                }
            }else{
                player.push_front(s);
                player.push_back(f);
                umap[s]++;
                if(umap[s] >= k){
                    return s;
                }
            }
        }
        return 0;
    }
};