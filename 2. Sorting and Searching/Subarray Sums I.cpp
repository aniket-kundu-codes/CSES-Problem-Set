#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    int i = 0, j = 0, cs = 0;
    while (j < n)
    {
        while (j < n and cs < x)
            cs += a[j], j++;
        while (cs > x)
            cs -= a[i], i++;
        if (cs == x)
            ans++, cs -= a[i], i++;
    }
    ans += cs == x;
    cout << ans << endl;

    return 0;
}