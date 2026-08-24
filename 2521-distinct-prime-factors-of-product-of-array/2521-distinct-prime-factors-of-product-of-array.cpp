class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> primes;
        for (int num : nums) {
            for (int p = 2; (long long)p * p <= num; p++) {
                while (num % p == 0) {
                    primes.insert(p);
                    num /= p;
                }
            }
            if (num > 1) primes.insert(num);
        }
        return primes.size();
    }
};