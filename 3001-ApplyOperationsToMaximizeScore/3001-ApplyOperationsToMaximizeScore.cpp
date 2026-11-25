// Last updated: 11/25/2026, 3:40:32 PM
class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long base, long long exponent) {
        long long res = 1;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res;
    }

    vector<int> getPrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

        for (int number = 2; number <= limit; number++) {
            if (!isPrime[number]) continue;

            primes.push_back(number);

            for (long long multiple = (long long)number * number; multiple <= limit; multiple += number) {
                isPrime[multiple] = false;
            }
        }

        return primes;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n, 0);

        int maxElement = *max_element(nums.begin(), nums.end());

        vector<int> primes = getPrimes(maxElement);

        for (int i = 0; i < n; i++) {
            int num = nums[i];

            for (int prime : primes) {
                if (prime * prime > num)
                    break; 
                if (num % prime != 0)
                    continue;  

                primeScores[i]++; 
                while (num % prime == 0)
                    num /= prime; 
            }

            if (num > 1) primeScores[i]++;
        }

        vector<int> nextDominant(n, n);
        vector<int> prevDominant(n, -1);

        stack<int> decreasingPrimeScoreStack;

        for (int i = 0; i < n; i++) {
            while (!decreasingPrimeScoreStack.empty() &&
                   primeScores[decreasingPrimeScoreStack.top()] < primeScores[i]) {
                int topIndex = decreasingPrimeScoreStack.top();
                decreasingPrimeScoreStack.pop();

                nextDominant[topIndex] = i;
            }

            if (!decreasingPrimeScoreStack.empty())
                prevDominant[i] = decreasingPrimeScoreStack.top();

            decreasingPrimeScoreStack.push(i);
        }


        vector<long long> numOfSubarrays(n);
        for (int i = 0; i < n; i++) {
            numOfSubarrays[i] = (long long)(nextDominant[i] - i) * (i - prevDominant[i]);
        }

        vector<pair<int, int>> sortedArray(n);
        for (int i = 0; i < n; i++) {
            sortedArray[i] = {nums[i], i};
        }

        sort(sortedArray.begin(), sortedArray.end(), greater<>());

        long long score = 1;
        int processingIndex = 0;

        while (k > 0) {
            auto [num, index] = sortedArray[processingIndex++];
            long long operations = min((long long)k, numOfSubarrays[index]);
            score = (score * power(num, operations)) % MOD;
            k -= operations;
        }

        return score;
    }
};


// class Solution {
// public:
//     const int MOD = 1e9 + 7; 
//     int maximumScore(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int>primeScore(n,1);
//         for(int i = 0;i < n;i++){
//             int num = nums[i];
//             for(int factor = 2;factor*factor <= num;factor++){
//                 if(num % factor == 0){
//                     primeScore[i]++;
//                     while(num % factor == 0) num /= factor;
//                 }
//             }
//             if(num >= 2)primeScore[i]++;
//         }
//         vector<int>prevDominant(n,-1);
//         vector<int>nextDominant(n,n);

//         stack<int>decreasingPrimeScoreStack;

//         for(int i = 0;i < n;i++){
//             while(!decreasingPrimeScoreStack.empty() && primeScore[decreasingPrimeScoreStack.top()] < primeScore[i]){
//                 int topIndex = decreasingPrimeScoreStack.top();
//                 decreasingPrimeScoreStack.pop();
//                 nextDominant[topIndex] = i;
//             }
//             if(!decreasingPrimeScoreStack.empty()){
//                 prevDominant[i] = decreasingPrimeScoreStack.top();
//             }
//             decreasingPrimeScoreStack.push(i);
//         }
//         vector<long long>numOfSubArrays(n);

//         for(int i = 0;i < n;i++){
//             numOfSubArrays[i] = (long long)(nextDominant[i] - i) * (i - prevDominant[i]);
//         }

//         priority_queue<pair<int,int>>processingQueue;

//         for(int i = 0;i < n;i++){
//             processingQueue.push({nums[i],i});
//         }

//         long long score = 1;

//         while(k > 0){
//             auto [num,index] = processingQueue.top();
//             processingQueue.pop();
//             long long operations = min((long long)k,numOfSubArrays[index]);
//             score = (score * power(num,operations)) % MOD;
//             k -= operations;
//         }
//         return score;
//     }
//     long long power(long long base,long long exp){
//         long long res = 1;
//         while(exp > 0){
//             if(exp % 2 == 1){
//                 res = (res * base) % MOD;
//             }
//             exp /= 2;
//             base = (base * base) % MOD;
//         }
//         return res;
//     }
// };
