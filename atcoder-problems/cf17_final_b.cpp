#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                  \
  ifstream in("atcoder-problems/cf17_final_b.txt"); \
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

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  string s;
  cin >> s;

  int a = 0, b = 0, c = 0;
  rep(i, s.size()) {
    if (s[i] == 'a') a++;
    if (s[i] == 'b') b++;
    if (s[i] == 'c') c++;
  }

  int minimum = min(min(a, b), c);
  a -= minimum;
  b -= minimum;
  c -= minimum;
  vector<int> d({a, b, c});
  sort(d.begin(), d.end(), greater<int>());

  int mod = s.size() % 3;
  if (a + b + c != mod || (mod == 0 && a + b + c == 3)) {
    cout << "NO" << endl;
    return 0;
  }

  bool ok = false;
  if (mod == 0) {
    if (d[0] != 3) ok = true;
  } else if (mod == 2) {
    if (d[0] == d[1]) ok = true;
  } else {
    ok = true;
  }

  cout << (ok ? "YES" : "NO") << endl;
}