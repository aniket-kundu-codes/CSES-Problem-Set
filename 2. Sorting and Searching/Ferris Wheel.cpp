#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(p.begin(), p.end());
    int ans = 0;
    int pt = 0;
    for (int i = n - 1; i >= pt; i--)
    {
        ans++;
        if (i != pt and p[i] + p[pt] <= x)
            pt++;
    }
    cout << ans << endl;
    return 0;
}