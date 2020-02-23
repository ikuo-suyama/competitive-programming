#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

int main() {
  ifstream in("ac-ans-b/abc032_c.txt");
  cin.rdbuf(in.rdbuf());

  ll N, K;
  cin >> N >> K;

  vector<int> s(N);
  rep(i, N) {
    int n;
    cin >> n;
    if(n == 0) {
      cout << N << endl;
      return 0;
    } else {
      s[i] = n;
    }
  }

  ll buf = s[0];
  int cnt = 0;
  int l = 0;
  repi(r, 1, N) {
    buf = buf * s[r];
    if (buf <= K) {
      cnt = max(r - l + 1, cnt);
    } else {
      while (buf * s[r] > K && l < r) {
        buf /= s[l++];
      }
    }
  }

  cout << cnt << endl;
}