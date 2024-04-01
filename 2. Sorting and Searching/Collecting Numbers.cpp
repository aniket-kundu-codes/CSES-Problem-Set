#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pos[x] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; i++)
        ans += pos[i] > pos[i + 1];
    cout << ans << endl;

    return 0;
}