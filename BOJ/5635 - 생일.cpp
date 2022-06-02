//
//  5635 - 생일.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/02.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
typedef struct _person {
    string name;
    int dd;
    int mm;
    int yyyy;
}person;

person p[101];

bool cmp(person &a, person &b){
    if(a.yyyy != b.yyyy) return a.yyyy > b.yyyy;
    else if(a.mm != b.mm) return a.mm > b.mm;
    else return a.dd > b.dd;
}
int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p[i].name >> p[i].dd >> p[i].mm >> p[i].yyyy;
    }
    sort(p, p + N, cmp);
    cout << p[0].name << "\n";
    cout << p[N - 1].name << "\n";
}
