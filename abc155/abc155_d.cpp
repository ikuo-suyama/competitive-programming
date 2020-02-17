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
  vector<ll> c(N, 0);
  rep(i, N) {
    ll a;
    cin >> a;
    if (a < 0) {
      n.push_back(a);
    } else {
      p.push_back(a);
    }
    c[i] = a;
  }

  vector<ll> ans;
  rep(i, N) for (int j = i + 1; j < N; j++) { ans.push_back(c[i] * c[j]); }

  sort(ans.begin(), ans.end());

  cout << ans[K -1] << endl;
}