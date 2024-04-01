#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    long long ans = -1e9, psum = 0, dip = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        psum += x;
        ans = max(ans, psum - dip);
        dip = min(dip, psum);
    }
    cout << ans << endl;
    return 0;
}