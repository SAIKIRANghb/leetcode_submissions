// Last updated: 11/25/2026, 3:43:12 PM
const int MOD = 1e9 + 7; 
const int MAX = 1e4 + 10;

class Solution {
public:
   vector<long long>fact,invFact;
   long long binExp(long long x,long long y){
        long long ans = 1;
        x = x % MOD;
        while(y > 0){
            if(y % 2 == 1){
                ans = (ans * x) % MOD;
            }
            y = y / 2;
            x = (x * x) % MOD;
        }
        return ans;
   }
    void precompute(){
        fact.resize(MAX + 1,1);
        invFact.resize(MAX + 1,1);

        for(int i = 2;i <= MAX;i++){
            fact[i] = (fact[i - 1] * i) % MOD;
        } 
        invFact[MAX] = binExp(fact[MAX] , MOD - 2);
        for(int i = MAX - 1;i >= 1;i--){
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }
    unordered_map<int,int> primeFactors(int k){
        unordered_map<int,int>factors;
        for(int i = 2;i * i <= k;i++){
            while(k % i == 0){
                factors[i]++;
                k = k / i;
            }
        }
        if(k > 1)factors[k]++;
        return factors;
    }
    long long ncr(long long n, long long r){
        if(r < 0 || r > n || n > MAX || r > MAX)return 0;
        return (fact[n] * invFact[r] % MOD) * invFact[n - r] % MOD;
    }
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int>ans;
        precompute();
        for(vector<int> &query : queries){
            int n = query[0];
            int k = query[1];
            long long ways = 1;
            unordered_map<int,int>factors = primeFactors(k);
            for(auto &[prime , exp] : factors){
                // exp + n - 1 number of symbols and number of ways to assume n - 1 symbols 
                //are bars is given by below expression
                ways = ways * ncr(exp + n - 1,n - 1) % MOD; 
            }
            ans.push_back(ways);
        }
        return ans;
    }
};