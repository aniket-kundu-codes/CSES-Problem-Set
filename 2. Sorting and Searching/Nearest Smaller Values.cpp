#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    vector<int> ids, nsl(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        while (ids.size() and x[ids.back()] > x[i])
            nsl[ids.back()] = i + 1, ids.pop_back();
        ids.push_back(i);
    }
    for (int i = 0; i < n; i++)
        cout << nsl[i] << " \n"[i == n - 1];

    return 0;
}