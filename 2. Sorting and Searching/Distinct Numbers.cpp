#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    set<int> distincts;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        distincts.insert(x);
    }
    cout << distincts.size() << endl;
    return 0;
}