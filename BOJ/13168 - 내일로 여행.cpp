//
//  13168 - 내일로 여행.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/09.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MX = 100;
const int INF = INT_MAX / 100;

int N, M, R, K, cnt, diff;
unordered_map<string, int> city;

int D[2][MX][MX];
vector<int> dest;

int trans_code(string &str) {
  if(str[0] == 'S' && str[1] == '-') return 1; // S-train: 50% 할인
  else if(str[0] == 'V') return 1; // V-train: 50% 할인
  else if(str[0] == 'I' || str[0] == 'M') return 2; // ITX, 무궁화: 공짜
  return 0;
}

int main() {
    FASTIO
    cin >> N >> R;
    R *= 2;
    
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        city.find(name);
        if (city.find(name) == city.end()) {
            city[name] = cnt;
            cnt++;
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        string name;
        cin >> name;
        dest.push_back(city[name]);
    }
    
    for (int i = 0; i < N; i++) {
        fill(D[0][i], D[0][i] + N, INF);
        fill(D[1][i], D[1][i] + N, INF);
    }
    
    for (int i = 0; i < N; i++) {
        D[0][i][i] = 0;
        D[1][i][i] = 0;
    }
    
    cin >> K;
    for (int i = 0; i < K; i++) {
        string type, s, e;
        int cost;
        cin >> type >> s >> e >> cost;
        cost *= 2;
        
        int u = city[s];
        int v = city[e];
        
        cost = min(D[0][u][v], cost);
        D[0][u][v] = D[0][v][u] = cost;
        
        int trcode = trans_code(type);
        if (trcode == 1) cost /= 2;
        else if (trcode == 2) cost = 0;
        
        cost = min(D[1][u][v], cost);
        D[1][u][v] = D[1][v][u] = cost;
    }
    
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++) {
            for (int k = 0; k < cnt; k++) {
                for (int m = 0; m < 2; m++) {
                    D[m][j][k] = min(D[m][j][k], D[m][j][i] + D[m][i][k]);
                }
            }
        }
    }
    
    for (int i = 1; i < dest.size(); i++) {
        int u = dest[i - 1];
        int v = dest[i];
        R -= D[0][u][v];
        R += D[1][u][v];
    }
    
    if (R < 0) cout << "Yes";
    else cout << "No";
    return 0;
}
