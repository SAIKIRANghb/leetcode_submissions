// Last updated: 11/25/2026, 3:41:45 PM
class NumberContainers {
public:
    unordered_map<int,int>ind2num;
    unordered_map<int,set<int>>num2ind;
    NumberContainers() {
        ind2num.clear();
        num2ind.clear();
    }
    
    void change(int index, int number) {
        if(ind2num.count(index)){
            if(ind2num[index] != number){
                int currNum = ind2num[index];
                num2ind[currNum].erase(index);
                if(num2ind[currNum].size() == 0)num2ind.erase(currNum);
                ind2num[index] = number;
                num2ind[number].insert(index);
            }
        }else{
            ind2num[index] = number;
            num2ind[number].insert(index);
        }
    }
    
    int find(int number) {
        if(!num2ind.count(number))return -1;
        return *num2ind[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */