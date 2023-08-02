//
//  18110 - solved.ac.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/02.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, sum, ans;

int main() {
    FASTIO
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    sort(numbers.begin(), numbers.end());
    
    int startIdx = round(n * 0.15);
    int endIdx = n - round(n * 0.15);
    for (int i = startIdx; i < endIdx; i++) {
        sum += numbers[i];
    }
    ans = round((double)sum / (double)(endIdx - startIdx));
    cout << ans;
    return 0;
}
