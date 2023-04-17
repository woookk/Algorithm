//
//  13314 - 플로이드에 오타가?.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/16.
//

#include <iostream>
using namespace std;

int dist[102][102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 100;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
      dist[i][j] = 10000;
      if(i == n || j == n ) dist[i][j] = 4999;
      if(i == j) dist[i][j] = 0;
    }

  cout << n << '\n';
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
      cout << dist[i][j] << ' ';
      if(j == n) cout << '\n';
    }
}
