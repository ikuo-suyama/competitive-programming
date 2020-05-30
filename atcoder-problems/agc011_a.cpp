#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc011_a.txt"); \
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

  ll N, C, K;
  cin >> N >> C >> K;

  vector<ll> c(N);
  rep(i, N) { cin >> c[i]; }
  sort(c.begin(), c.end());

  ll ans = 0;
  int cur = 0;
  int waitIdx = 0;
  int waitNum = 1;
  ll time = c[0] + K;
  while (cur < N) {
    if (waitNum >= C) {
      if (c[cur] > time) {
        // 乗れない
        waitIdx = cur;
        time = c[cur] + K;
        waitNum = 1;
        ans++;
        cur++;
      } else {
        // 乗れる
        cur++;
        waitIdx = cur;
        time = c[waitIdx] + K;
        waitNum = 0;
        ans++;
      }
    } else if (c[cur] > time) {
      waitIdx = cur;
      time = c[waitIdx] + K;
      waitNum = 1;
      ans++;
      cur++;
    } else {
      cur++;
      waitNum++;
    }
  }
  if (waitNum > 0) ans++;

  cout << ans << endl;
}