#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0, pt = 0;
    for (int i = 0; i < n; i++)
    {
        while (pt < m and b[pt] < a[i] - k)
            pt++;
        if (pt != m and b[pt] <= a[i] + k)
            ans++, pt++;
    }
    cout << ans << endl;
    return 0;
}