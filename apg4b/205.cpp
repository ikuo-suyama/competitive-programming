#include <bits/stdc++.h>
using namespace std;

// x番の組織について、子組織からの報告書が揃った時刻を返す
// childrenは組織の関係を表す2次元配列(参照渡し)
int count_documents(vector<vector<int>> &children, vector<int> &retCount, int x)
{
  if (children.at(x).size() == 0)
  {
    retCount.at(x) = 1;
    return 1;
  }
  else
  {
    vector<int> c = children.at(x);
    int ret = 0;
    for (int i = 0; i < c.size(); i++)
    {
      ret += count_documents(children, retCount, c.at(i));
    }
    ret++;
    retCount.at(x) = ret;
    return ret;
  }
}

// これ以降の行は変更しなくてよい

int main()
{
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  vector<int> p(N); // 各組織の親組織を示す配列
  p.at(0) = -1;     // 0番組織の親組織は存在しないので-1を入れておく
  for (int i = 1; i < N; i++)
  {
    cin >> p.at(i);
  }

  // 組織の関係から2次元配列を作る
  vector<vector<int>> children(N); // ある組織の子組織の番号一覧  // N×0の二次元配列
  for (int i = 1; i < N; i++)
  {
    int parent = p.at(i);             // i番の親組織の番号
    children.at(parent).push_back(i); // parentの子組織一覧にi番を追加
  }

  vector<int> ret(N);
  count_documents(children, ret, 0);
  for (int i = 0; i < N; i++)
  {
    cout << ret.at(i) << endl;
  }
}