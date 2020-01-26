#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main() {
  ifstream in("abc153/d.txt");
  cin.rdbuf(in.rdbuf());

  ll H;
  cin >> H;

  ll n = 0;
  do {
    n++;
  } while (pow(2, n) <= H);

  ll ret = (1 - pow(2, n)) / (1 - 2);
  cout << ret << endl;
}