#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/arc099_a.txt"); \
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

  int N, K;
  cin >> N >> K;
  
  vector<int> c(N);
  int s = 0;
  rep(i, N) { 
    cin >> c[i];
    if (c[i] == 1) s = i;
  }

  ll ans = INF;
  repi(i, s - K, s + 1) {
    ll tmp = 0;
    int l = max(0, i);
    int r = N - min(i + K, N);
    tmp = ceil((double)l / (K - 1)) + ceil((double)r / (K - 1));
    ans = min(tmp, ans);
  }

  cout << ans + 1 << endl;
}