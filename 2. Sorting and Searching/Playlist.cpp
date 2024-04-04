#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, ans = 0;
    cin >> n;
    queue<int> num;
    map<int, bool> has;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (has[x])
        {
            while (num.front() != x)
            {
                has[num.front()] = false;
                num.pop();
            }
            num.pop();
        }
        num.push(x);
        has[x] = true;
        ans = max(ans, (int)num.size());
    }
    cout << ans << endl;
    return 0;
}