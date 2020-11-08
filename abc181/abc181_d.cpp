#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc181/abc181_d.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v)                        \
  rep(l, v.size()) { cout << v[l] << " "; } \
  cout << endl;
#else
#define INPUT_FILE
#define print_vec(v)
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
typedef pair<ll, ll> pl;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

bool solve(string& S) {
  if (S.size() == 1) return S == "8";
  if (S.size() == 2) {
    if (stoi(S) % 8 == 0) return 1;
    swap(S[0], S[1]);
    return stoi(S) % 8 == 0;
  }

  int N = S.size();
  vector<int> c(10, 0);
  rep(i, N) { c[S[i] - '0']++; }

  for (int i = 8; i < 1000; i += 8) {
    string d = to_string(i);
    if (d.size() == 1) d = "00" + d;
    if (d.size() == 2) d = "0" + d;

    vector<int> dd(10, 0);
    rep(j, d.size()) dd[d[j] - '0']++;

    bool ok = true;
    rep(j, 10) {
      if (dd[j] > c[j]) {
        ok = false;
        break;
      }
    }

    if (ok) return 1;
  }

  return 0;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  string S;
  cin >> S;

  cout << (solve(S) ? "Yes" : "No") << endl;
}