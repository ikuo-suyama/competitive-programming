#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc161/abc161_d.txt"); \
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

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int K;
  cin >> K;

  queue<ll> que;
  repi(i, 1, 10) { que.push(i); }
  rep(i, K - 1) {
    ll s = que.front();
    que.pop();
    for (int j = -1; j <= 1; j++) {
      int add = (s % 10) + j;
      if (add >= 0 && add <= 9) que.push(s * 10 + add);
    }
  }

  cout << que.front() << endl;
}