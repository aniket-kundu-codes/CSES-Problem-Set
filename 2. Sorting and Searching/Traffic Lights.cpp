#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int x, n, p;
    cin >> x >> n;
    set<int> lights;
    multiset<int> ans;
    lights.insert(0), lights.insert(x);
    ans.insert(x);
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        auto it = lights.lower_bound(p);
        auto it2 = prev(it);

        // delete
        ans.erase(ans.find(*it - *it2));
        // add
        ans.insert(p - *it2);
        ans.insert(*it - p);
        lights.insert(p);

        cout << *ans.rbegin() << " ";
    }

    return 0;
}