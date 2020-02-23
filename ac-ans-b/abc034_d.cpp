#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

int main() {
  ifstream in("ac-ans-b/abc034_d.txt");
  cin.rdbuf(in.rdbuf());

  int N, K;
  cin >> N >> K;

  vector<ll> w(N);
  vector<ll> p(N);
  rep(i, N) { cin >> w[i] >> p[i]; }

  double l = 0, r = 100;
  int cnt = 0;
  while (l < r && cnt < 100) {
    cnt++;
    double x = (l + r) / 2;

    // 塩の過不足量、 index
    vector<double> salt(N);
    rep(i, N) { salt[i] = w[i] * (p[i] - x); }
    sort(salt.begin(), salt.end(), greater<double>());

    double tot_s = 0;
    rep(i, K) { tot_s += salt[i]; }

    // printf("tot_s: %f x:%f\n", tot_s, x);
    if (tot_s <= 0) {
      r = x;
    } else {
      l = x;
    }
  }
  printf("%f", l);
}