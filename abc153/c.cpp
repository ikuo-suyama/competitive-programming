#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main() {
  ifstream in("abc153/c.txt");
  cin.rdbuf(in.rdbuf());

  int N, K;
  cin >> N >> K;

  vector<ll> h(N);
  rep(i, N) { cin >> h[i]; }

  sort(h.begin(), h.end(), greater<int>());

  ll ret = 0;
  if (K < N) {
    ret = accumulate(next(h.begin(), K), h.end(), (ll)0);
  }

  cout << ret << endl;
}