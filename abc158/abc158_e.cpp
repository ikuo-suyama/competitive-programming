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

  ll ans = 0;
  int N, P;
  cin >> N >> P;

  string S;
  cin >> S;

  map<int, ll> modP;
  repi(i, 1, N + 1) {
    int mod = 0;
    // 10桁区切りでmodを計算
    rep(j, i / 10 + 1) {
      int len = min(10, i - (10 * j));
      if (len == 0) break;
      int st = N - (j == 0 ? i : min(10 * j, i));
      printf("i:%d, j:%d, len:%d, st:%d\n", i, j, len, st);
      printf("%s\n", S.substr(st, len).c_str());
      printf("%s\n", S.substr(N-i, i).c_str());
      ll x = stoll(S.substr(st, len));
      // ll x = stoll(S.substr(N-i, i));
      mod += x % P;
    }

    insert_or_cntup(modP, mod);
    ans += modP.at(mod);
    if (mod != 0) ans--;
  }

  printf("%d, %d, %d, %d\n", 1000 % 7, 123 % 7, 456 % 7, 123456 % 7);

  cout << ans << endl;
}