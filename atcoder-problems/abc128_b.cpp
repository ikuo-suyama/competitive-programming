#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc128_b.txt"); \
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

  multimap<string, vector<P>> sorted_map;
  rep(i, N) {
    string s;
    int p;
    cin >> s >> p;
    if (sorted_map.find(s) == sorted_map.end()){
      sorted_map.emplace(s, vector<P>(1, make_pair(p,i)));
    } else {
      sorted_map.find(s)->second.push_back(make_pair(p, i));
    }
  }

  for(auto kv : sorted_map) {
    sort(kv.second.begin(), kv.second.end(), greater<P>());
    for(auto v : kv.second) {
      cout << v.second + 1 << endl;
    }
  }

}