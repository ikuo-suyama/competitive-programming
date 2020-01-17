#include <bits/stdc++.h>
using namespace std;

int main()
{
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());

  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++)
  {
    cin >> A.at(i) >> B.at(i);
  }

  vector<vector<string>> ret(N, vector<string>(N, "-"));

  for (int i = 0; i < M; i++)
  {
    ret.at(A.at(i) - 1).at(B.at(i) - 1) = "o";
    ret.at(B.at(i) - 1).at(A.at(i) - 1) = "x";
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (j == N - 1) {
        cout << ret.at(i).at(j);
      } else {
        cout << ret.at(i).at(j) << " "; 
      }
    }
    cout << endl;
  }
}