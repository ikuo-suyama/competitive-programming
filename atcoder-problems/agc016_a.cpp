#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc016_a.txt"); \
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
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

bool isSame(string s) {
  bool ret = true;
  rep(i, s.size() - 1) { ret &= s[i] == s[i + 1]; }
  return ret;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  string s;
  cin >> s;

  map<char, int> m;
  rep(i, s.size()) { m[s[i]] += 1; }
  int mx = 0, mxi = 0;
  for (auto kv : m) {
    if (mx < kv.second) {
      mx = kv.second;
      mxi = kv.first;
    }
  }

  set<char> se(s.begin(), s.end());
  mxi = 'r';
  int cnt = 0;
  while (!isSame(s)) {
    cnt++;
    string sd = s.substr(0, s.size() - 1);
    rep(i, sd.size() - 1) {
      if (s[i] == mxi || s[i+1] == mxi) {
        sd[i] = mxi;
      } else {
        sd[i] = s[i];
      }
    }
    s = sd;
    cout << sd << endl;
  }
  cout << cnt << endl;
}