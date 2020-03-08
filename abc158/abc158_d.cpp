#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                     \
  ifstream in("abc158/abc158_d.txt"); \
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

  int q;
  cin >> q;

  string pre = "";
  string sus = "";
  bool rev = false;
  rep(i, q) {
    int t;
    cin >> t;
    if (t == 1) {
      rev = !rev;
      pre.swap(sus);
    } else {
      int f;
      cin >> f;
      char c;
      cin >> c;
      if (f == 1) {
        pre += c;
      } else {
        sus += c;
      }
    }
  }

  if (rev) {
    reverse(s.begin(), s.end());
  }
  reverse(pre.begin(), pre.end());

  cout << pre + s + sus << endl;
}