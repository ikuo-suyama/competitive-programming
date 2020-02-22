#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

int main() {
  ifstream in("ac-ans-b/codefestival_2015_qualA_d.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;
  
  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }

  ll cnt = 0;

  cout << cnt << endl;
}