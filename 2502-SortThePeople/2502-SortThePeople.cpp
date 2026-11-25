// Last updated: 11/25/2026, 3:41:30 PM
class Solution {
public:
    int partitionInd(int low,int high,vector<string>&names,vector<int>&heights){
        int pivot = heights[high];
        int i = low - 1;

        for(int j = low;j<=high-1;j++){
            if(heights[j] > pivot){
                i++;
                swap(heights[i],heights[j]);
                swap(names[i],names[j]);
            }
        }
        swap(heights[i+1],heights[high]);
        swap(names[i+1],names[high]);
        return i + 1;
    }
    void quickSort(int low,int high,vector<string>&names,vector<int>&heights){
        if(low >= high)return;
        int pI = partitionInd(low,high,names,heights);
        quickSort(low,pI-1,names,heights);
        quickSort(pI + 1,high,names,heights);
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        quickSort(0,heights.size() - 1,names,heights);
        return names;
    }
};