#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc148_e.txt"); \
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

/**
 * 整数
 * あるNのうち、Pで割り切れるものの数は N / P
 * 100 の中に 5 で割り切れる数は 100 / 5 個ある
 * 末尾に0をつける -> 5の倍数の数 と 2の倍数の組み合わせ
 * #integer
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll N;
  cin >> N;

  if (N % 2 != 0) {
    cout << 0 << endl;
    return 0;
  }

  ll prime = 5 * 2;
  ll ans = 0;
  while (prime <= N) {
    ans += N / prime;
    prime *= 5;
  }

  cout << ans << endl;
}