#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

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
    int l = -1, r = N;
    while (l + 1 < r) {
      int x = (l + r) / 2;
      if (mid > a[x]) {
        l = x;
      } else {
        r = x;
      }
    }
    low_cnt = r;

    // 上限の２分探索
    l = -1, r = N;
    while (l + 1 < r) {
      int x = (l + r) / 2;
      if (mid >= c[x]) {
        l = x;
      } else {
        r = x;
      }
    }
    high_cnt = N - r;

    ans += low_cnt * high_cnt;
    // printf("i:%d, l:%lld, r:%lld\n", i, low_cnt, high_cnt);
  }
  cout << ans << endl;
}