#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                  \
  ifstream in("atcoder-problems/sumitb2019_d.txt"); \
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

ll comb(int n, int k) {
  if (k == 0) return 1;
  if (n / 2 < k) return comb(n, n - k);
  ll ans = 1;
  vector<int> p(0);
  vector<int> q(0);
  rep(i, k) { p.push_back(n - i); }
  repi(i, 1, k + 1) { q.push_back(i); }
  rep(i, k) {
    ans *= p[i];
    ans /= q[i];
  }

  return ans;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  string S;
  cin >> N >> S;

  map<char, int> mp;
  rep(i, N) { mp[S[i]]++; }

  int n = 0, m = 0, l = 0;
  for (auto kv : mp) {
    if (kv.second == 1)
      n++;
    else if (kv.second == 2)
      m++;
    else if (kv.second >= 3)
      l++;
  }

  ll ans = 0;
  // すべてバラバラ
  ans += comb(n + m + l, 3);
  // 2つ同じ
  ans += n * comb(m + l, 2) * 3;
  ans += m * comb(m + l - 1, 2) * 3;
  ans += l * comb(m + l - 1, 2) * 3;
  // 3つ同じ
  ans += comb(m, 1);

  cout << ans << endl;
}