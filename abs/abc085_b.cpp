#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main() {
  ifstream in("abs/abc085.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }

  ll ret = 0;
  sort(a.begin(), a.end(), greater<int>());
  rep(i, N) {
    if (a[i] != a[i + 1]) ret++;
  }
  cout << ret << endl;
}