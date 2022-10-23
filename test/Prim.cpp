//
//  Prim.cpp
//  Algorithm
//
//  Created by 민병욱 on 2022/09/20.
//

#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

class TRI {
public:
    int a, b, w;
};

class PQ { // w가 작을수록 먼저 나오는 것.
public:
    int n;
    TRI Arr[1000];
    PQ();
    TRI Delete();
    void Insert(TRI x);
    int isEmpty();
};

PQ::PQ() {
    n = 0;
}

int PQ::isEmpty() {
    return n == 0;
}

void PQ::Insert(TRI x){
    int i;
    Arr[n + 1] = x;
    i = n + 1;
    n++;
    while(i > 1 && Arr[i].w < Arr[i / 2].w) { // i가 1이면 끝남
        swap(Arr[i], Arr[i / 2]);
        i /= 2;
    }
}

TRI PQ::Delete() {
    TRI ret = Arr[1];
    int i, j;
    if (n == 1) { // special case 처리
        n = 0;
        return ret;
    }
    Arr[1] = Arr[n];
    i = 1; n = n - 1;
    while(1) {
        if (i * 2 > n) { // Child X
            break;
        }
        else if (i * 2 + 1 > n) { // Left Child Only
            if (Arr[i * 2].w < Arr[i].w) {
                swap(Arr[i * 2], Arr[i]);
                i = i * 2;
            }
            else {
                break;
            }
        }
        else { // Left and Right Child exists
            if (Arr[i].w > Arr[i * 2].w && Arr[i].w > Arr[i * 2 + 1].w) {
                if (Arr[i].w < Arr[i * 2 + 1].w)
                    j = i * 2;
                else
                    j = i * 2 +1;
                swap(Arr[i], Arr[j]);
                i = j;
            }
            else if (Arr[i].w > Arr[i * 2].w && Arr[i].w <= Arr[i * 2 + 1].w) {
                j = i * 2;
                swap(Arr[i], Arr[j]);
                i = j;
            }
            else if (Arr[i].w <= Arr[i * 2].w && Arr[i].w > Arr[i * 2 + 1].w) {
                j = i * 2 + 1;
                swap(Arr[i], Arr[j]);
                i = j;
            }
            else {
                break;
            }
        }
    }
    return ret;
}

PQ Q;

int n, m;
vector<pair<int, int>> Edges[1000];
int M[1000]; // Marking

int main(){
    /*
    TRI s[100] = {
        {1, 2, 3},
        {4, 5, 6},
        {2, 2, 4},
        {4, 2, 1},
        {4, 2, 2},
        {4, 6, 8}
    };
    TRI t;
    Q.Insert(s[0]);
    Q.Insert(s[1]);
    Q.Insert(s[2]);
    Q.Insert(s[3]);
    Q.Insert(s[4]);
    Q.Insert(s[5]);
    t = Q.Delete();
    printf("Deleted (%d %d %d)\n", t.a, t.b, t.w);
    */
    
    ///*
    int c, i, a, b, w;
    TRI x, y;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &w);
        Edges[a].push_back(make_pair(b, w));
        Edges[b].push_back(make_pair(a, w));
    }
    c = 1; M[c] = 1;
    for (i = 0; i < Edges[c].size(); i++) { // 1번 Node에 대해 다 집어넣는다.
        x.a = c; x.b = Edges[c][i].first;
        x.w = Edges[c][i].second;
        Q.Insert(x);
    }
    while (Q.isEmpty() == 0) {
        y = Q.Delete();
        if (M[y.a] == 1 && M[y.b] == 1) {
            continue;
        }
        else {
            c = y.b; M[c] = 1;
            printf("Edge from Node %d to Node %d of Weight %d Selected\n", y.a, y.b, y.w);
            for (i = 0; i < Edges[c].size(); i++) {
                x.a = c; x.b = Edges[c][i].first; x.w = Edges[c][i].second; Q.Insert(x);
            }
        }
    }
    //*/
    return 0;
}

/*
5 10
1 2 10
2 3 1
1 5 6
1 4 5
2 4 4
2 4 3
4 5 2
3 4 9
3 5 4
5 3 6
 */
