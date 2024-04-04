#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using pbset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    pbset<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    int current_rank = 0;
    for (int len = n; len >= 1; len--)
    {
        int next_rank = (current_rank + k) % len;
        auto it = s.find_by_order(next_rank);
        cout << *it << " ";
        s.erase(it);
        if (len != 1)
            current_rank = next_rank % (len - 1);
    }
    return 0;
}