// Last updated: 11/25/2026, 3:40:15 PM
// class Solution {
// public:
//     int find(int a,unordered_map<int,int> &parent){
//         if(parent[a] != a){
//             parent[a] = find(parent[a],parent);
//         }
//         return parent[a];
//     }
//     void Union(int a,int b,unordered_map<int,int> &parent){
//         int rootA = find(a,parent);
//         int rootB = find(b,parent);
//         if(rootA != rootB){
//             parent[rootB] = rootA;
//         }
//     }
//     vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
//         vector<int>sortedNums = nums;
//         unordered_map<int,int>parent;

//         for(int i = 0;i < nums.size();i++){
//             parent[nums[i]] = nums[i];
//         }

//         sort(sortedNums.begin(),sortedNums.end());

//         for(int i = 1;i < sortedNums.size();i++){
//             if(sortedNums[i] - sortedNums[i - 1] <= limit){
//                 Union(sortedNums[i],sortedNums[i - 1],parent);
//             }
//         }

//         unordered_map<int,queue<int>>gr2q;

//         for(int i = 0;i < sortedNums.size();i++){
//             gr2q[find(sortedNums[i],parent)].push(sortedNums[i]);
//         }

//         vector<int>ans;

//         for(int i = 0;i < nums.size();i++){
//             int group = find(nums[i],parent);
//             ans.push_back(gr2q[group].front());
//             gr2q[group].pop();
//         }

//         return ans;
//     }
// };

// // class Solution {
// // public:
// //     vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
// //         int n = nums.size(); 
// //         vector<int>arr = nums;
// //         sort(arr.begin(),arr.end());

// //         unordered_map<int,list<int>>gr2num;
// //         unordered_map<int,int>num2gr;

// //         int gr_no = 0;
// //         gr2num[0].push_back(arr[0]);
// //         num2gr[arr[0]] = gr_no;

// //         for(int i = 1;i < n;i++){
// //             if(abs(arr[i - 1] - arr[i]) <= limit){
// //                 gr2num[gr_no].push_back(arr[i]);
// //                 num2gr[arr[i]] = gr_no;
// //             }else{
// //                 gr_no++;
// //                 gr2num[gr_no].push_back(arr[i]);
// //                 num2gr[arr[i]] = gr_no;
// //             }
// //         }

// //         for(int i = 0;i<n;i++){
// //             int gr = num2gr[nums[i]];
// //             int fr = gr2num[gr].front();
// //             gr2num[gr].pop_front();
// //             nums[i] = fr;
// //         }
// //         return nums;
// //     }
// // };

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end());

        int currGroup = 0;
        unordered_map<int, int> numToGroup;
        numToGroup.insert(pair<int, int>(numsSorted[0], currGroup));

        unordered_map<int, list<int>> groupToList;
        groupToList.insert(
            pair<int, list<int>>(currGroup, list<int>(1, numsSorted[0])));

        for (int i = 1; i < nums.size(); i++) {
            if (abs(numsSorted[i] - numsSorted[i - 1]) > limit) {
                // new group
                currGroup++;
            }

            // assign current element to group
            numToGroup.insert(pair<int, int>(numsSorted[i], currGroup));

            // add element to sorted group list
            if (groupToList.find(currGroup) == groupToList.end()) {
                groupToList[currGroup] = list<int>();
            }
            groupToList[currGroup].push_back(numsSorted[i]);
        }

        // iterate through input and overwrite each element with the next
        // element in its corresponding group
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int group = numToGroup[num];
            nums[i] = *groupToList[group].begin();
            groupToList[group].pop_front();
        }

        return nums;
    }
};