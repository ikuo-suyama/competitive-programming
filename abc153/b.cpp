#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main() {
  ifstream in("abc153/b.txt");
  cin.rdbuf(in.rdbuf());

  int H, N;
  cin >> H >> N;

  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }

  ll max = accumulate(c.begin(), c.end(), 0);

  string ret = H > max ? "No" : "Yes";

  cout << ret << endl;
}