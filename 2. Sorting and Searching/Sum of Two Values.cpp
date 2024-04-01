#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, value;
    cin >> n >> x;
    map<int, vector<int>> a;
    for (int i = 1; i <= n; i++)
    {
        cin >> value;
        a[value].push_back(i);
    }
    int u = -1, v;
    for (auto &[value, indices] : a)
    {
        int need = x - value;
        if (need == value)
        {
            if (indices.size() >= 2)
            {
                u = indices[0];
                v = indices[1];
                break;
            }
        }
        else if (a.find(need) != a.end())
        {
            u = indices[0];
            v = a[need][0];
            break;
        }
    }

    if (u == -1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << u << " " << v << endl;

    return 0;
}