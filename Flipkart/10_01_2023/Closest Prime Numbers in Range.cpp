class Solution {
public:
    // const int N = sqrt(1e9+40);
 
#define eb emplace_back

vector<bool> segement_sieve(int a, int b)
{
    int l = sqrt(b);
    vector<bool> mark(l + 1, true);
    vector<int> primes;
    for (int i = 2; i <= l; i++)
    {
        if (mark[i])
        {
            primes.eb(i);
            for (int j = 1LL * i * i; j <= l; j += i)
            {
                mark[j] = 0;
            }
        }
    }

    vector<bool> isprime(b - a + 1, true);
    for (auto x : primes)
    {
        for (int prime = (a + x - 1) / x * x; prime <= b; prime += x)
        {
            if (prime != x)
            {
                isprime[prime - a] = false;
            }
        }
    }

    if (a == 1)
    {
        isprime[0] = false;
    }

    return isprime;
}
    
    vector<int> closestPrimes(int left, int right) {
        vector<bool> is = segement_sieve(left,right);
        int n = is.size();
        vector<int> primes;
        for(int i=0; i<n; i++){
            if(is[i]){
                primes.eb(i+left);
            }
        }
        sort(primes.begin(),primes.end());
        if(primes.size()<=1){
            return {-1,-1};
        }
        int diff = 1e9;
        int x = -1, y = -1;
        n = primes.size();
        for(int i=0; i<n-1; i++){
            if (primes[i + 1] - primes[i] < diff){
            diff = primes[i + 1] - primes[i];
            x = primes[i], y = primes[i+1];
            }
        }
        return {x,y};
    }
};
