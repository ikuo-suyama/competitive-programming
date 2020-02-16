#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("abc155/abc155_d.txt");
  cin.rdbuf(in.rdbuf());

  int N, K;
  cin >> N >> K;

  vector<ll> p, n;
  rep(i, N) {
    ll a;
    cin >> a;
    if (a < 0) {
      n.push_back(a);
    } else {
      p.push_back(a);
    }
  }

  ll ans = 0;
  if (K < n.size() * p.size()) {
  }

  sort()
  rep(i, N) rep(j, N) {

  }

  ll cnt = 0;

  cout << cnt << endl;
}