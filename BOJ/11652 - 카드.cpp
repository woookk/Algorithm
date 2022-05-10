//
//  11652 - 카드.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/10.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
long long a[100001];
int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a, a + N);
    int cnt = 1;
    long long mxval = -((long long)1 << 62) - 1;
    int mxcnt = 0;
    a[N] = ((long long)1 << 62) + 1;
    for(int i = 1; i <= N; i++){
        if(a[i - 1] == a[i]) cnt++;
        else {
            if(cnt > mxcnt){
                mxcnt = cnt;
                mxval = a[i - 1];
            }
            cnt = 1;
        }
    }
    cout << mxval;
    return 0;
}
