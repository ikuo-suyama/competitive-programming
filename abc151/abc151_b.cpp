#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

int main() {
  ifstream in("abc151/abc151_b.txt");
  cin.rdbuf(in.rdbuf());

  int N, K, M;
  cin >> N >> K >> M;

  ll sum = 0;
  rep(i, N - 1) {
    int a;
    cin >> a;
    sum += a;
  }

  ll ans = (M * N) - sum;
  if (ans < 0) ans = 0;
  if (ans > K) ans = -1;
  cout << ans << endl;
}