//
//  13144 - List of Unique Numbers.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/18.
//

#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int N;
ll ans;
int a[100001];

int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    vector<bool> chk(100002);
    int en = 0;
    chk[a[0]] = 1;
    for(int st = 0; st < N; st++){
        while(en < N - 1 && !chk[a[en + 1]]){
            en++;
            chk[a[en]] = 1;
        }
        ans += (en - st + 1);
        chk[a[st]] = 0;
    }
    cout << ans;
    return 0;
}
