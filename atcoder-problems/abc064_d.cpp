#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc064_d.txt"); \
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

  int N;
  string S;
  cin >> N >> S;

  int l = 0, r = 0;
  int tl = 0, tr = 0;
  rep(i, N) {
    if (S[i] == '(') {
      if (i > 0 && S[i - 1] == ')') {
        tl += l;
        l = 1;
        tr += r;
        r = 0;
      } else if (r > 0)
        r--;
      else
        l++;
    } else {
      if (l > 0) l--;
      else
        r++;
    }
  }
  tr += r;
  tl += l;

  rep(i, tr) { cout << '('; }
  cout << S;
  rep(i, tl) { cout << ')'; }
}