#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("abc154/abc154_a.txt");
  cin.rdbuf(in.rdbuf());

  string s, t;
  cin >> s >> t;

  int a, b;
  cin >> a >> b;

  string u;
  cin >> u;

  if (u == s) {
    a--;
  } else {
    b--;
  }

  cout << a << ' ' << b << endl;
}