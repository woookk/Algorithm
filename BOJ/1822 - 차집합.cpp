//
//  1822 - 차집합.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/13.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, m;
vector<int> A, B;

int main() {
    FASTIO
    cin >> n >> m;

    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        A.push_back(num);
    }
    for (int i = 0; i < m; ++i) {
        cin >> num;
        B.push_back(num);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<int> ans;
    for (int num : A) {
        if (binary_search(B.begin(), B.end(), num)) continue;
        ans.push_back(num);
    }
    cout << ans.size() << "\n";
    for (int num : ans){
        cout << num << " ";
    }
    return 0;
}
