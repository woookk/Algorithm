//
//  1269 - 대칭 차집합.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/01/04.
//

#include <iostream>
#include <unordered_set>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int A, B;
unordered_set<int> setA;
int overlap;

int main() {
    FASTIO
    cin >> A >> B;
    for (int i = 0; i < A; i++) {
        int num;
        cin >> num;
        setA.insert(num);
    }
    for (int i = 0; i < B; i++) {
        int num;
        cin >> num;
        if (setA.find(num) != setA.end()) {
            overlap++;
        }
    }
    
    cout << A  + B - 2 * overlap;
    return 0;
}
