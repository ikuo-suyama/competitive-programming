#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("ac-ans-a/tdpc_contest.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  set<int> s{0};

  rep(i, N) {
    int c;
    cin >> c;
    set<int> t(s);
    for (auto a : t) {
      s.insert(a + c);
    }
  }

  cout << s.size() << endl;
}