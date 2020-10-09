#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/arc103_a.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v)                        \
  rep(l, v.size()) { cout << v[l] << " "; } \
  cout << endl;
#else
#define INPUT_FILE
#define print_vec(v)
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
typedef pair<ll, ll> pl;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;

  unordered_map<int, int> even;
  unordered_map<int, int> odd;

  rep(i, N) {
    int c;
    cin >> c;
    if (i % 2 == 0)
      even[c]++;
    else
      odd[c]++;
  }

  priority_queue<P> evenQue;
  priority_queue<P> oddQue;

  for (auto kv : even) {
    evenQue.push({kv.second, kv.first});
  }
  for (auto kv : odd) {
    oddQue.push({kv.second, kv.first});
  }
  evenQue.push({0, -1});
  oddQue.push({0, -1});

  P maxE = evenQue.top();
  evenQue.pop();
  P maxO = oddQue.top();
  oddQue.pop();

  int ans;

  if (maxE.second != maxO.second) {
    ans = (N / 2) - maxO.first + ceil((float)N / 2) - maxE.first;
  } else {
    P nextE = evenQue.top();
    P nextO = oddQue.top();
    if (nextE.first > nextO.first) {
      ans = (N / 2) - maxO.first + ceil((float)N / 2) - nextE.first;
    } else {
      ans = (N / 2) - nextO.first + ceil((float)N / 2) - maxE.first;
    }
  }

  cout << ans << endl;
}