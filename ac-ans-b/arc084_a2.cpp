#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

// 二分探索 - stdlib
// https://pyteyon.hatenablog.com/entry/2019/02/20/194140#stdlower_bound-%E3%81%A8-stdupper_bound
int main() {
  ifstream in("ac-ans-b/arc084_a.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  vector<int> a(N);
  vector<int> b(N);
  vector<int> c(N);
  rep(i, N) { cin >> a[i]; }
  rep(i, N) { cin >> b[i]; }
  rep(i, N) { cin >> c[i]; }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  ll ans = 0;
  rep(i, N) {
    int mid = b[i];
    ll low_cnt, high_cnt;

    // 下段の２分探索
    auto liter = lower_bound(a.begin(), a.end(), mid);
    low_cnt = distance(a.begin(), liter);

    // 上限の２分探索
    auto hiter = upper_bound(c.begin(), c.end(), mid);
    high_cnt = N - distance(c.begin(), hiter);

    ans += low_cnt * high_cnt;
  }
  cout << ans << endl;
}