#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main() {
  ifstream in("abc152/d.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  int c[10][10] = {};

  for (size_t i = 1; i <= N; i++) {
    string s = to_string(i);
    c[s[0] - '0'][s.back() - '0']++;
  }

  ll ret = 0;
  for (size_t i = 1; i < 10; i++) {
    for (size_t j = 1; j < 10; j++) {
      ret += c[i][j] * (ll)c[j][i];
    }
  }
  cout << ret << endl;
}