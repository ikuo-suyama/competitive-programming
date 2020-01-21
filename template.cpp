#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main() {
  // input.txt から cin
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());

  // N個の変数を配列に格納
  int N;
  cin >> N;

  int c[N];
  rep(i, N) { cin >> c[i]; }

  ll cnt = 0;

  cout << cnt << endl;
}