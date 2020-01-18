#include <bits/stdc++.h>
using namespace std;

int main() {
  // input.txt から cin
  ifstream in("abc/practice-a.txt");
  cin.rdbuf(in.rdbuf());

  // N個の変数を配列に格納
  int a,b,c;
  cin >> a >> b >> c;

  string s;
  cin >> s;

  cout << (a + b + c) << " " << s;
}
