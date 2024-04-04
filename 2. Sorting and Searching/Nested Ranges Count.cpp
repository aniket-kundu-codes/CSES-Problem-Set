#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using pbmultiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// pbset<int> s;
// s.insert(5); //insertion in O(logn)
// *s.find_by_order(1) //element at index t in O(logn)
// s.order_of_key(5) //position of 5 or rank of 5 or how many elements less than 5
// always use iterator :  auto it=s.find_by_order(s.order_of_key(value));  and not find()
// then use s.erase(it) or s.erase(s.find_by_order(s.order_of_key(value)));
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int n, a, b;
    cin >> n;
    set<array<int, 3>> points;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        points.insert({a, 1, i});
        points.insert({b, -a, i});
    }
    vector<int> ans1(n, 0), ans2(n, 0);
    pbmultiset<int> starts;
    pbmultiset<int> starts_finished;
    auto above = [&](int ele)
    {
        return int(starts_finished.size()) - starts_finished.order_of_key(ele);
    };
    int upto = -1;
    for (auto [x, y, id] : points)
    {
        if (y == 1)
            starts.insert(x);
        else
        {
            y = -y;
            ans1[id] = above(y);
            ans2[id] = starts.order_of_key(y + 1) - 1;
            starts.erase(starts.find_by_order(starts.order_of_key(y)));
            starts_finished.insert(y);
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans1[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; i++)
        cout << ans2[i] << " \n"[i == n - 1];

    return 0;
}