#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("abc159/abc159_b.txt"); \
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
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  string s;
  cin >> s;

  string sr(s);
  reverse(sr.begin(), sr.end());

  string l = s.substr(0, (s.size() - 1) / 2);
  string lr(l);
  reverse(lr.begin(), lr.end());

  string r = s.substr((s.size() + 3) / 2 - 1, s.size());
  string rr(r);
  reverse(rr.begin(), rr.end());

  // printf("%s %s %s %s\n", l.c_str(), lr.c_str(), r.c_str(), rr.c_str());

  bool ok = s == sr && l == lr && r == rr;

  cout << (ok ? "Yes" : "No") << endl;
}