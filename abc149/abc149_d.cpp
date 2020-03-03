#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc149/abc149_d.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, K, R, S, P;
  cin >> N >> K >> R >> S >> P;

  map<char, int> points;
  // 勝利したときの点
  points.emplace('r', R);
  points.emplace('s', S);
  points.emplace('p', P);
  map<char, char> win;
  // 勝てる手
  win.emplace('s', 'r');
  win.emplace('p', 's');
  win.emplace('r', 'p');

  string t;
  cin >> t;

  // Group化
  vector<vector<char>> o(K, vector<char>(0));
  rep(i, N) { o[i % K].push_back(t[i]); }

  vector<char> org{'r', 's', 'p'};
  ll ans = 0;

  rep(k, K) {
    // 貪欲法
    int sz = o[k].size();
    vector<char> i(sz);
    rep(l, sz) {
      if (l == 0) {
        i[l] = win.at(o[k][l]);
        ans += points.at(i[l]);
      } else if (i[l - 1] == win.at(o[k][l])) {
        if (l < sz - 1) {
          // 同じ手が出せない
          for (char x : org) {
            if (x != win.at(o[k][l]) && x != win.at(o[k][l + 1])) {
              i[l] = x;
              break;
            }
          }
        }
      } else {
        i[l] = win.at(o[k][l]);
        ans += points.at(i[l]);
      }
    }
  }

  cout << ans << endl;
}