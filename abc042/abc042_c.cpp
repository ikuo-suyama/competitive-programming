#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("abc042/abc042_c.txt"); \
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

  string N;
  int K;
  cin >> N >> K;
  
  set<int> s{0,1,2,3,4,5,6,7,8,9};
  rep(i, K) {
    int d;
    cin >> d;
    s.erase(d);
  }
  vector<int> c(s.begin(), s.end());
  sort(c.begin(), c.end());

  string ans = "";
  // 1桁目
  int i = lower_bound(c.begin(), c.end(), N[0]) - c.begin();
  bool upper
  if (i < c.size()) {

  }

  cout << ans << endl;
}