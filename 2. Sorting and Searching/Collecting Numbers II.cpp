#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), pos(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; i++)
        ans += pos[i] > pos[i + 1];

    auto op = [&](int val, int change)
    {
        if (val > 1 and val <= n and pos[val - 1] > pos[val])
            ans += change;
    };
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int vx = a[x], vy = a[y];
        if (vx > vy)
            swap(vx, vy);

        // delete
        op(vx, -1);
        op(vx + 1, -1);
        if (vx + 1 != vy)
            op(vy, -1);
        op(vy + 1, -1);

        // swap
        swap(a[x], a[y]);
        swap(pos[vx], pos[vy]);

        // add
        op(vx, 1);
        op(vx + 1, 1);
        if (vx + 1 != vy)
            op(vy, 1);
        op(vy + 1, 1);

        cout << ans << endl;
    }

    return 0;
}