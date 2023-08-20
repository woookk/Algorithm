//
//  11723 - 집합.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/20.
//

#include <iostream>
#include <string>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int M;
int main() {
    FASTIO
    cin >> M;

    string order;
    int x, BIT = 0;
    while (M--) {
        cin >> order;
        if (order.compare("add") == 0) {
            cin >> x;
            BIT |= (1 << x);
        }
        else if (order.compare("remove") == 0) {
            cin >> x;
            BIT &= ~(1 << x);
        }
        else if (order.compare("check") == 0) {
            cin >> x;
            if (BIT & (1 << x)) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
                
        }
        else if (order.compare("toggle") == 0) {
            cin >> x;
            BIT ^= (1 << x);
        }
        else if (order.compare("all") == 0) {
            BIT = (1 << 21) - 1;
        }
        else if (order.compare("empty") == 0) {
            BIT = 0;
        }
    }
    return 0;
}
