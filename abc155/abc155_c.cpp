#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

typedef pair<int, string> PS;

bool cmp(PS &i, PS &j) {
  bool ret = i.first > j.first;
  if (i.first == j.first) {
    ret = i.second < j.second;
  }
  return ret;
}

int main() {
  ifstream in("abc155/abc155_c.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  map<string, int> m;
  rep(i, N) {
    string s;
    cin >> s;

    decltype(m)::iterator it = m.find(s);
    if (it != m.end()) {
      int cnt = it->second;
      m.erase(s);
      m.emplace(s, cnt + 1);
    } else {
      m.emplace(s, 1);
    }
  }

  vector<pair<int, string>> p;
  for (auto kv : m) {
    p.push_back(make_pair(kv.second, kv.first));
  }
  sort(p.begin(), p.end(), cmp);

  int max = p[0].first;
  cout << p[0].second << endl;
  repi(i, 1, N) {
    if (p[i].first < max) break;
    cout << p[i].second << endl;
  }
}