//
//  7453 - 합이 0인 네 정수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n;
long long ans;
int arr[4][4001];

int main(){
    FASTIO
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> arr[j][i];
        }
    }
    vector<int> sum1, sum2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum1.push_back(arr[0][i] + arr[1][j]);
            sum2.push_back(arr[2][i] + arr[3][j]);
        }
    }
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());
    for(int i = 0; i < (int)sum1.size(); i++){
        int lower = lower_bound(sum2.begin(), sum2.end(), -sum1[i]) - sum2.begin();
        int upper = upper_bound(sum2.begin(), sum2.end(), -sum1[i]) - sum2.begin();
        ans += upper - lower;
    }
    cout << ans;
    return 0;
}
