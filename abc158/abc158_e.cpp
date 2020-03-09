#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc158/abc158_e.txt"); \
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

void insert_or_cntup(map<int, ll>& m, int key) {
  auto it = m.find(key);
  if (it != m.end()) {
    ll cnt = it->second;
    m.erase(key);
    m.emplace(key, cnt + 1);
  } else {
    m.emplace(key, 1);
  }
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, P;
  cin >> N >> P;

  string S;
  cin >> S;

  int dig = 1;
  int cur = 0;
  ll ans = 0;
  map<int, ll> modP;
  rep(i, P) { modP.emplace(i, 0); }
  modP[0] = 1;

  if (P == 2 || P == 5) {
    rep(i, N) {
      if ((S[i] - '0') % P == 0) {
        ans += i + 1;
      }
    }
  } else {
    for (int i = N - 1; i >= 0; i--) {
      int tmp = (S[i] - '0') * dig;
      cur += tmp;
      cur %= P;
      dig *= 10;
      dig %= P;

      int mod = cur % P;
      ans += modP.at(mod);
      insert_or_cntup(modP, mod);
    }
  }
  cout << ans << endl;
}