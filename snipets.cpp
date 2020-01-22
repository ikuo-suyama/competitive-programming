#include <bits/stdc++.h>
using namespace std;

static bool endsWith(string& str, string& suffix) {
  return str.size() >= suffix.size() &&
         0 == str.compare(str.size() - suffix.size(), suffix.size(), suffix);
}
static bool startsWith(string& str, string& prefix) {
  return str.size() >= prefix.size() &&
         0 == str.compare(0, prefix.size(), prefix);
}

int main() {
  // input.txt から cin
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());

  // N個の変数を配列に格納
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }

  // N * M 個の変数を配列に格納
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
  }

  // vector min/max
  vector<int> vec;
  int min = *std::min_element(vec.begin(), vec.end());
  int max = *std::max_element(vec.begin(), vec.end());

  std::vector<int>::iterator minIt = std::min_element(vec.begin(), vec.end());
  std::vector<int>::iterator maxIt = std::max_element(vec.begin(), vec.end());

  // distance で vec の先頭イテレーターと minIt, maxIt との距離を取得する．
  // インデックスを取得したいときは，vec
  // の先頭イテレーターを指定する必要がある． 例えば，vec.begin() + 1
  // とか指定すると答えは変わる．
  size_t minIndex = std::distance(vec.begin(), minIt);
  size_t maxIndex = std::distance(vec.begin(), maxIt);

  // int to string & 一文字ずつ
  int i, c;
  string s = to_string(i);
  for (int j = 0; j < s.size(); j++) {
    c += (int)(s[j] - '0');
  }
}
