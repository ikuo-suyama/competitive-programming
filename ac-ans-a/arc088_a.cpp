#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("ac-ans-a/arc088_a.txt");
  cin.rdbuf(in.rdbuf());

  ll X, Y;
  cin >> X >> Y;

  ll a = X, cnt = 0;
  while (a <= Y) {
    cnt++;
    a *= 2;
  }

  cout << cnt << endl;
}