#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);

    auto it = s.begin();
    while (!s.empty())
    {
        if (s.size() == 1)
            cout << *it << " ";
        else
        {
            it++;
            if (it == s.end())
                it = s.begin();
            cout << *it << " ";
        }
        if (next(it) == s.end())
        {
            s.erase(it);
            it = s.begin();
        }
        else
        {
            it++;
            s.erase(prev(it));
        }
    }
    return 0;
}