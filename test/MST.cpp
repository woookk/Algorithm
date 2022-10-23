//
//  MST.cpp
//  DS
//
//  Created by 민병욱 on 2022/06/06.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

class edge {
public:
    int a, b, w;
    bool operator < (const edge& k) const
    {
        return w < k.w;
    }
};

vector<pair<int, int>> AD[1000];

edge ED[1000];
int isused[1000];

int n, m;

int A[1000];

int Find(int a){
    int r, p, q;
    p = a;
    while(A[p] != 0){
        p = A[p];
    }
    r = p; p = a;
    while(A[p] != 0){
        q = p;
        p = A[p];
        A[q] = r;
    }
    return p;
}

void Union(int a, int b){
    int p, q;
    p = Find(a); q = Find(b);
    if(p != q)
        A[q] = p;
    return;
}

int vis[1000];

void Print(int nd, int w, int d, int LR){
    int first;
    vis[nd] = 1;
    if(LR == 1)
        for(int i = 0; i < d; i++)
            cout << "         ";
    cout << setw(4) << "[" << w << ", " << nd << "]";
    first = 1;
    for(int i = 0; i < AD[nd].size(); i++){
        if(vis[AD[nd][i].first] == 0){
            if(first == 1){
                Print(AD[nd][i].first, AD[nd][i].second, d + 1, 0);
            }
            else {
                Print(AD[nd][i].first, AD[nd][i].second, d + 1, 1);
            }
            first = 0;
        }
    }
    if(first == 1){
        cout << "\n";
    }
}

int main(){
    
    cin >> n >> m;
    edge E;
    int sum;
    for(int i = 1; i <= m; i++){
        cin >> E.a >> E.b >> E.w;
        ED[i] = E;
    }
    sort(ED + 1, ED + m  + 1);
    for(int i = 1; i <= m; i++){
        if (Find(ED[i].a) != Find(ED[i].b)){
            cout << "Using Edge #" << i << ", between " << ED[i].a << " and " << ED[i].b << " with weight " << ED[i].w << "\n";
            isused[i] = 1;
            Union(ED[i].a, ED[i].b);
        }
    }
    sum = 0;
    for(int i = 1; i <= m; i++){
        if(isused[i] == 1)
            sum += ED[i].w;
    }
    cout << "Weight Sum = " << sum << "\n";
    for(int i = 1; i <= m; i++){
        if(isused[i]){
            AD[ED[i].a].push_back({ED[i].b, ED[i].w});
            AD[ED[i].b].push_back({ED[i].a, ED[i].w});
        }
    }
    Print(1, 0, 0, 0);
    return 0;
}

// input
/*
 5 10
 1 2 10
 1 4 5
 1 5 6
 2 3 1
 2 4 3
 2 4 4
 3 4 9
 3 5 4
 3 5 6
 4 5 2
 */
