//
//  20366 - 같이 눈사람 만들래?.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/22.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int ans = 1e9;
int a[601];

int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a, a + N);
    for(int i = 0; i < N; i++){
        for(int j = i + 3; j < N; j++){
            int st = i + 1;
            int en = j - 1;
            while(st < en){
                int anna = a[i] + a[j];
                int elsa = a[st] + a[en];
                int res = elsa - anna;
                ans = min(ans, abs(res));
                if(res > 0){
                    en = en - 1;
                }
                else {
                    st = st + 1;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
