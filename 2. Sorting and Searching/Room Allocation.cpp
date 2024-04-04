#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int n, a, b;
    cin >> n;
    set<int> available_rooms;
    set<array<int, 3>> time_stamp;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        time_stamp.insert({a, 0, i});
        time_stamp.insert({b, 1, i});
        available_rooms.insert(i);
    }
    vector<int> allocated(n);
    for (auto &[time, type, id] : time_stamp)
        if (type == 0)
        {
            allocated[id] = *available_rooms.begin();
            available_rooms.erase(available_rooms.begin());
        }
        else
            available_rooms.insert(allocated[id]);

    cout << *max_element(allocated.begin(), allocated.end()) + 1 << endl;
    for (int i = 0; i < n; i++)
        cout << allocated[i] + 1 << " \n"[i == n - 1];

    return 0;
}