#include <bits/stdc++.h>
using namespace std;
const int n = 8;
bool col[n];
bool leftd[2 * n];
bool rightd[2 * n];
int main()
{
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int ans = 0;

    vector<bool> leftd(2 * n, false), rightd(2 * n, false);
    auto update = [&](int i, int j)
    {
        col[j] = col[j] ^ 1;
        leftd[i - j + n] = leftd[i - j + n] ^ 1;
        rightd[i + j] = rightd[i + j] ^ 1;
    };
    function<void(int)> solve = [&](int level)
    {
        if (level == n)
        {
            ans++;
            return;
        }
        for (int i = 0; i < n; i++)
            if (s[level][i] == '.' and !col[i] and !leftd[level - i + n] and !rightd[level + i])
            {
                update(level, i);
                solve(level + 1);
                update(level, i);
            }
    };
    solve(0);
    cout << ans << endl;
    return 0;
}