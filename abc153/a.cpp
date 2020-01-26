#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main() {
  ifstream in("abc153/a.txt");
  cin.rdbuf(in.rdbuf());

  int H, A;
  cin >> H >> A;

  int cnt = ceil(H / (double)A);

  cout << cnt << endl;
}