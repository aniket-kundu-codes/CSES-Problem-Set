#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int n = s.size();
    string res = "";
    string other = "";
    for (int i = 1; i < n; i++)
        if (s[i] == s[i - 1])
            res += s[i], i++;
        else
            other += s[i - 1];
    if (n % 2 == 1 and other.size() == 0)
        other += s.back();
    if (2 * int(res.size()) + int(other.size()) == n and int(other.size()) <= 1)
    {
        cout << res;
        cout << other;
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    else
        cout << "NO SOLUTION" << endl;
    return 0;
}