#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                     \
  ifstream in("atcoder-problems/agc015_a.txt"); \
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
 * https://atcoder.jp/contests/agc015/tasks/agc015_a
 * 総和の組み合わせの数
 * 重複する組み合わせがある場合、組み合わせを数えなくても、
 * max - min が組み合わせの個数になる。
 * 
 * #integer #sum
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll N, A, B;
  cin >> N >> A >> B;

  ll max = A + B * (N - 1);
  ll min = A * (N - 1) + B;

  ll ans = max - min + 1;
  cout << (ans > 0 ? ans : 0) << endl;
}