#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc141_d.txt"); \
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

int loga(int x, int a) {
  if (x == 0 || x == 1) return 0;
  int cnt = 0;
  while (x % a == 0) {
    x /= a;
    cnt++;
  }
  return cnt;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, M;
  cin >> N >> M;

  priority_queue<ll> a;
  rep(i, N) {
    ll _a;
    cin >> _a;
    a.push(_a);
  }

  while (M > 0) {
    ll current = a.top();
    a.pop();
    ll next = 1;
    if (!a.empty()) next = a.top();
    if (next == 0) next = 1;

    ll num = loga(current / next, 2);
    if (num == 0) num++;
    if (num > M) num = M;

    current /= pow(2, num);
    M -= num;
    a.push(current);
  }

  ll ans = 0;
  while (!a.empty()) {
    ans += a.top();
    a.pop();
  }
  cout << ans << endl;
}