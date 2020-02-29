#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc150/abc150_c.txt"); \
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

  int N;
  cin >> N;

  vector<int> c(N);
  rep(i, N) { c[i] = i + 1; }

  string p;
  rep(i, N) {
    string _p;
    cin >> _p;
    p += _p;
  }
  string q;
  rep(i, N) {
    string _q;
    cin >> _q;
    q += _q;
  }

  vector<string> perm;
  do {
    string s = "";
    rep(i, N) { s += c[i] + '0'; }
    perm.push_back(s);
  } while (next_permutation(c.begin(), c.end()));

  int a = lower_bound(perm.begin(), perm.end(), p) - perm.begin();
  int b = lower_bound(perm.begin(), perm.end(), q) - perm.begin();

  cout << abs(a - b) << endl;
}