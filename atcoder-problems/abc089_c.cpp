#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc089_c.txt"); \
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

template <typename Iterator>
inline bool next_combination(const Iterator first, Iterator k,
                             const Iterator last) {
  /* Credits: Thomas Draper */
  if ((first == last) || (first == k) || (last == k)) return false;
  Iterator itr1 = first;
  Iterator itr2 = last;
  ++itr1;
  if (last == itr1) return false;
  itr1 = last;
  --itr1;
  itr1 = k;
  --itr2;
  while (first != itr1) {
    if (*--itr1 < *itr2) {
      Iterator j = k;
      while (!(*itr1 < *j)) ++j;
      iter_swap(itr1, j);
      ++itr1;
      ++j;
      itr2 = k;
      rotate(itr1, j, last);
      while (last != j) {
        ++j;
        ++itr2;
      }
      rotate(k, itr2, last);
      return true;
    }
  }
  rotate(first, k, last);
  return false;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;

  map<char, ll> m;
  rep(i, N) {
    string s;
    cin >> s;
    m[s[0]]++;
  }

  ll ans = 0;
  string a = "MARCH";
  rep(i, a.size() - 2) {
    repi(j, i + 1, a.size() - 1) {
      repi(k, j + 1, a.size()) {
        ans += m[a[i]] * m[a[j]] * m[a[k]];
      }
    }
  }
  cout << ans << endl;
}