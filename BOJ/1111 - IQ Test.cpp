//
//  1111 - IQ Test.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/04.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int num[55];

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    if (N == 1) {
        cout << "A";
    }
    else if (N == 2) {
        if (num[2] == num[1]) {
            cout << num[1];
        }
        else {
            cout << "A";
        }
    }
    else {
        int a = 0, b = 0;
        if (num[2] - num[1] != 0) {
            a = (num[3] - num[2]) / (num[2] - num[1]);
        }
        b = num[2] - num[1] * a;
        
        for (int i = 2; i <= N; i++) {
            if (num[i] != num[i - 1] * a + b) {
                cout << "B";
                return 0;
            }
        }
        cout << num[N] * a + b;
    }
    return 0;
}

/*
    앞 수 * a + b
    
    조건 분기
        N == 1일 때, 다음 수 여러 개 나올 수 있다.
        N == 2일 때, 두 수가 같으면 (a = 1, b = 0)이므로 다음 수가 정해지고 두 수가 다르면 다음 수 여러 개 나올 수 있다.
        N == 3일 때, 두 점끼리 기울기를 구해서 a를 구할 수 있고 a를 이용하여 b를 구할 수 있다. 모든 점 확인하면서 해당 직선 위에 있지 않을 시 다음 수를 구할 수 없다.
 */
