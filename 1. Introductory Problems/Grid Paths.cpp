#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char dir[] = {'R', 'D', 'L', 'U'};

int main()
{

  int n = 7;
  auto inside = [&](int i, int j)
  {
    return i >= 0 and i < n and j >= 0 and j < n;
  };
  vector<vector<bool>> vis(n, vector<bool>(n, false));
  vector<vector<int>> bounded(n, vector<int>(n, 0));
  vector<vector<vector<array<int, 3>>>> neighbour(n, vector<vector<array<int, 3>>>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int move = 0; move < 4; move++)
        if (inside(i + dx[move], j + dy[move]))
          neighbour[i][j].push_back({i + dx[move], j + dy[move], move});
        else
          bounded[i][j]++;
  bounded[n - 1][0]--;
  vector<vector<int>> paths;
  vector<int> curr_path;
  function<void(int, int)> store = [&](int i, int j)
  {
    if (i == n - 1 and j == 0)
    {
      if (int(curr_path.size()) == n * n - 1)
        paths.push_back(curr_path);
      return;
    }
    vis[i][j] = true;

    for (auto &[x, y, z] : neighbour[i][j])
      if (!vis[x][y])
        bounded[x][y]++;

    int have_to = 0;
    int which = -1;
    vector<int> valid;
    for (auto &[x, y, z] : neighbour[i][j])
      if (!vis[x][y])
      {
        valid.push_back(z);
        if (bounded[x][y] == 3)
          have_to++, which = z;
      }

    if (have_to == 0)
    {
      if (valid.size() == 2 and valid[0] + 2 == valid[1])
        valid.clear();

      for (auto &move : valid)
      {
        if ((i == 0 and move == 2) or (i == n - 1 and move == 0) or (j == 0 and move == 3) or (j == n - 1 and move == 3))
          continue;
        curr_path.push_back(move);
        store(i + dx[move], j + dy[move]);
        curr_path.pop_back();
      }
      valid.clear();
    }
    else if (have_to == 1)
    {
      valid.clear();
      curr_path.push_back(which);
      store(i + dx[which], j + dy[which]);
      curr_path.pop_back();
    }

    // clear
    vis[i][j] = false;
    for (auto &[x, y, z] : neighbour[i][j])
      if (!vis[x][y])
        bounded[x][y]--;
  };
  store(0, 0);

  string s;
  cin >> s;
  int ans = 0;
  n = s.size();
  for (auto &current_path : paths)
  {
    bool is_same = true;
    for (int i = 0; i < n; i++)
      if (s[i] != '?' and s[i] != dir[current_path[i]])
      {
        is_same = false;
        break;
      }
    ans += is_same;
  }
  cout << ans << endl;
  return 0;
}