//
//  10815 - 숫자 카드.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/13.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int a[500001];

int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a, a + N);
    cin >> M;
    while(M--){
        int tmp;
        cin >> tmp;
        cout << binary_search(a, a + N, tmp) << " ";
    }
    return 0;
}
