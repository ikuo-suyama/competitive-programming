#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

bool cmp(P &i, P &j) { return i.second < j.second; }

/**
 * 区間スケジューリング
 * https://qiita.com/drken/items/e77685614f3c6bf86f44
 *
 * 末尾の要素でソートする
 */
int main() {
  ifstream in("ac-ans-a/abc103_d.txt");
  cin.rdbuf(in.rdbuf());

  int N, M;
  cin >> N >> M;

  int c[M];
  vector<P> ab(M);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    ab[i] = make_pair(a, b);
  }
  sort(ab.begin(), ab.end(), cmp);

  vector<int> ret(1, ab[0].second - 1);
  rep(i, M) {
    int a = ab[i].first;
    int b = ab[i].second;
    if (ret.back() < a) {
      ret.push_back(b - 1);
    }
  }

  cout << ret.size() << endl;
}