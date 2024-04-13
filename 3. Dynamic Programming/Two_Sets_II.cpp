#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int power(int a, int n)
{
    if (n == 0)
        return 1;
    int p = power(a, n / 2);
    p = (1ll * p * p) % mod;
    if (n & 1)
        p = (1ll * p * a) % mod;
    return p;
}
int main()
{
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2 == 0)
    {
        sum /= 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = sum; j >= i; j--)
                dp[j] = (dp[j] + dp[j - i]) % mod;
        }
        // Fermat's little theorem a^(p-2) %mod = a^-1 %mod
        cout << (1ll * dp[sum] * power(2, mod - 2)) % mod << endl;
    }
    else
        cout << 0 << endl;
    return 0;
}