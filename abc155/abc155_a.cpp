#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("abc155/abc155_a.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;
  
  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }

  ll cnt = 0;

  cout << cnt << endl;
}