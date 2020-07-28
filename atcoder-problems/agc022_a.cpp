#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc022_a.txt"); \
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

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  string S;
  cin >> S;
  string abc = "abcdefghijklmnopqrstuvwxyz";
  if (S.size() != abc.size()) {
    map<char, int> m;
    rep(i, S.size()) { m[S[i]]++; }
    rep(i, abc.size()) {
      if (!m[abc[i]]) {
        cout << S << abc[i] << endl;
        return 0;
      }
    }
  } else {
    char last = S.back();
    reverse(S.begin(), S.end());
    rep(i, S.size() - 1) {
      if (S[i] > S[i + 1]) {
        reverse(S.begin(), S.end());
        rep(j, S.size() - i - 2) { cout << S[j]; }
        cout << last;
        return 0;
      }
    }
    cout << -1 << endl;
    return 0;
  }
}