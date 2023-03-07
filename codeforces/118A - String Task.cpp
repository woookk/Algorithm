//
// Created by 민병욱 on 2023/03/06.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string word;

int main() {
    FASTIO
    cin >> word;
    for (char c : word) {
        if (c >= 65 && c < 97) {
            c = c + 32;
        }

        if (c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i') {
            continue;
        }
        else {
            cout << "." << c;
        }
    }
    return 0;
}
