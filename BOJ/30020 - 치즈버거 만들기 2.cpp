//
//  30020 - 치즈버거 만들기 2.cpp
//  cpp
//
//  Created by 민병욱 on 2023/09/20.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int A, B;
int ans;

int main() {
    FASTIO
    cin >> A >> B;
    if (A > 2 * B || A <= B) {
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    ans = A - B;
    cout << ans << "\n";
    while (--ans) {
        cout << "aba\n";
        A -= 2;
        B--;
    }
    string remain = "a";
    for (int i = 0; i < B; i++) {
        remain += "ba";
    }
    cout << remain << "\n";
    return 0;
}

/*
 요리 재료로 사용할 햄버거 패티가 A개, 슬라이스 치즈가 B개
 치즈버거를 만들기 위해서는 패티와 치즈를 각각 한 개 이상 고른 후 햄버거 빵 사이에 패티와 치즈를 쌓아야 한다.
 (단, 패티의 개수는 치즈의 개수보다 정확히 한 개 더 많이 골라야 한다.)
 치즈버거를 몇 개 만들어서 가게의 요리 재료를 모두 사용하려고 한다. 패티와 치즈를 모두 사용하려면 치즈버거를 각각 어떻게 만들어야 하는지 구해보자.
 
 패티와 치즈를 모두 사용하는 방법이 있다면 YES를, 그렇지 않다면 NO를 출력한다.
 
 최대 개수
 A = 2B
 
 최소 개수
 A = B + 1
 
 최대 개수 일 경우 햄버거 최대 B개, 최소 개수 일 경우 1개
 최소 개수부터 A가 하나씩 증가할 때마다 분해된다고 ABA 생긴다고 생각
 
 */
