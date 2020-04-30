#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc143/abc143_d.txt"); \
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
 * 二分探索 - 汎化
 * #binarysearch #二分探索
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;

  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }
  sort(c.begin(), c.end(), greater<>());

  ll cnt = 0;

  rep(i, N) repi(j, i + 1, N - 1) {
    int diff = c[i] - c[j];
    // この関数が最初にfalseを返す位置のイテレータの位置
    // true, true, false
    //             ^
    auto comp = [&](int x) -> bool {
      return x > diff;
    };
    auto startIt = c.begin() + j + 1;
    auto it = partition_point(startIt, c.end(), comp);
    auto l = it - startIt;
    cnt += l;
  }

  cout << cnt << endl;
}