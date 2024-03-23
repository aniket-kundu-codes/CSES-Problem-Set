#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    function<int(int, int)> power = [&](int a, int b)
    {
        if (b == 0)
            return 1;
        int result = power(a, b / 2);
        result = (1ll * result * result) % mod;
        if (b & 1)
            result = (1ll * result * a) % mod;
        return result;
    };
    cout << power(2, n) << endl;
    return 0;
}