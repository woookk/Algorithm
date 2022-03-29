//
//  15684 - 사다리 조작.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/29.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

#define X first
#define Y second

bool ladder[32][12];
int idxs[3];
vector<pair<int, int>> coords;
int n, m, h;

bool check() {
  for (int j = 1; j <= n; j++) {
    int cur = j;
    for (int i = 1; i <= h; i++) {
      if (ladder[i][cur - 1]) cur--;
      else if (ladder[i][cur]) cur++;
    }
    if (cur != j) return false;
  }
  return true;
}

int main() {
    FASTIO;
    cin >> n >> m >> h;
    while (m--) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;
    }

  for (int i = 1; i <= h; i++)
    for (int j = 1; j < n; j++) {
      if (ladder[i][j - 1] || ladder[i][j] || ladder[i][j + 1]) continue;
      coords.push_back({i, j});
    }


  if(check()){
    cout << 0;
    return 0;
  }

  int ans = 0x7f7f7f7f;
  int sz = coords.size();
  for(int i = 0; i < sz; i++){
    ladder[coords[i].X][coords[i].Y] = true;
    if(check()) ans = min(ans, 1);
    for(int j = i+1; j < sz; j++){
      ladder[coords[j].X][coords[j].Y] = true;
      if(check()) ans = min(ans, 2);
      for(int k = j+1; k < sz; k++){
        ladder[coords[k].X][coords[k].Y] = true;
        if(check()) ans = min(ans, 3);
        ladder[coords[k].X][coords[k].Y] = false;
      }
      ladder[coords[j].X][coords[j].Y] = false;
    }
    ladder[coords[i].X][coords[i].Y] = false;
  }
  if(ans == 0x7f7f7f7f) ans = -1;
  cout << ans;
}
