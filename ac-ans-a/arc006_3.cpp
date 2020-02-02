#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("ac-ans-a/arc006_3.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;
  
  vector<int> ans(0);

  rep(i, N) {
    bool update = false;
    int w;
    cin >> w;
    rep(j, ans.size()) {
      if(ans[j] >= w) {
        ans[j] = w;
        sort(ans.begin(), ans.end(), less<int>());
        update = true;
        break;
      }
    }
    if (!update) {
      ans.push_back(w);
    }
  }

  cout << ans.size() << endl;
}