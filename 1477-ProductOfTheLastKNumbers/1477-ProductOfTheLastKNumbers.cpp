// Last updated: 11/25/2026, 3:43:58 PM
class ProductOfNumbers {
public:
    vector<int>nums;
    int n;
    ProductOfNumbers() {
        nums = {1};
        n = 1;
    }
    
    void add(int num) {
        if(num == 0){
            nums = {1};
            n = 1;
        }else {
            nums.push_back(nums.back()*num);
            n++;
        }
    }
    
    int getProduct(int k) {
        if(k >= n){
            return 0;
        }else{
            return nums.back() / nums[n - k - 1];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */