#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("ac-ans-a/abc085_b.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;
  
  set<int> c;
  rep(i, N) {
    int _c;
    cin >> _c;
    c.insert(_c);
  }

  cout << c.size() << endl;
}