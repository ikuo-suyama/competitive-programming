#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("abc155/abc155_a.txt");
  cin.rdbuf(in.rdbuf());

  int a, b, c;
  cin >> a >> b >> c;

  string ret = "No";
  if ((a == b && b != c) || (a == c && a != b) || (b == c && a != b)) {
    ret = "Yes";
  }

  cout << ret << endl;
}