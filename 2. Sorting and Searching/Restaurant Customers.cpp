#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b;
    cin >> n;
    set<pair<int, char>> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        s.insert({a, 'A'});
        s.insert({b, 'L'});
    }
    int maxi = 0, current = 0;
    for (auto &[time_stamp, status] : s)
    {
        current += status == 'A' ? 1 : -1;
        maxi = max(maxi, current);
    }
    cout << maxi << endl;
    return 0;
}