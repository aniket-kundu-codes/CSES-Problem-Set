#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int k = 1; k <= n; k++)
    {
        long long ans = 1ll * k * k * (k * k - 1) / 2;
        // |x1-x2|=1 and |y1-y2|=2
        ans -= (k - 1) * 2 * (k - 2);
        // |x1-x2|=2 and |y1-y2|=1
        ans -= (k - 2) * 2 * (k - 1);
        cout << ans << endl;
    }

    return 0;
}