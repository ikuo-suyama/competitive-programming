#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/abc160_e.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v) \
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
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;

  vector<ll> p(A), q(B), r(C);
  rep(i, A) { cin >> p[i]; }
  rep(i, B) { cin >> q[i]; }
  rep(i, C) { cin >> r[i]; }

  sort(p.rbegin(), p.rend());
  sort(q.rbegin(), q.rend());
  sort(r.rbegin(), r.rend());
  vector<ll> pp(X);
  vector<ll> qq(Y);
  rep(i, X) { pp[i] = p[i]; }
  rep(i, Y) { qq[i] = q[i]; }

  sort(pp.begin(), pp.end());
  sort(qq.begin(), qq.end());

  ll ans = 0;
  int pi = 0, qi = 0, ri = 0;
  while (pi < X && qi < Y && ri < C) {
    if (pp[pi] > qq[qi]) {
      if (qq[qi] < r[ri]) {
        qq[qi] = r[ri];
        qi++;
        ri++;
      } else {
        break;
      }
    } else {
      if (pp[pi] < r[ri]) {
        pp[pi] = r[ri];
        pi++;
        ri++;
      } else {
        break;
      }
    }
  }
  if (pi < X && ri < C) {
    while(pi < X && ri < C) {
      if (pp[pi] < r[ri]) {
        pp[pi] = r[ri];
        pi++;
        ri++;
      } else {
        break;
      }
    }
  } else if (qi < Y && ri < C) {
    while(qi < Y && ri < C) {
      if (qq[qi] < r[ri]) {
        qq[qi] = r[ri];
        qi++;
        ri++;
      } else {
        break;
      }
    }
  }

  rep(i, X) { ans += pp[i]; }
  rep(i, Y) { ans += qq[i]; }

  cout << ans << endl;
}