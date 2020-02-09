#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("abc154/abc154_c.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;
  
  vector<ll> c(N);
  set<ll> d;
  rep(i, N) {
    ll a;
    cin >> a;
    c[i] = a;
    d.insert(a);
  }

  string ans = c.size() == d.size() ? "YES" : "NO";
  cout << ans << endl;
}