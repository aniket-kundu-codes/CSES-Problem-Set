#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, lim;
    cin >> n;
    long long total = 0, ans = 1e18, sum;
    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i], total += p[i];
    lim = 1 << n;
    for (int i = 0; i < lim; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                sum += p[j];
        ans = min(ans, abs(total - 2 * sum));
    }
    cout << ans << endl;

    return 0;
}