#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using pbmultiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    pbmultiset<int> s;
    for (int i = 0; i < k; i++)
        s.insert(x[i]);

    int median_index = (k - 1) / 2;
    cout << *s.find_by_order(median_index) << " ";
    for (int i = k; i < n; i++)
    {
        s.erase(s.find_by_order(s.order_of_key(x[i - k])));
        s.insert(x[i]);
        cout << *s.find_by_order(median_index) << " ";
    }
    return 0;
}