//
//  5052 - 전화번호 목록.cpp
//  cpp
//
//  Created by 병욱 민 on 7/30/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int tc;

int main() {
    FASTIO
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<string> phone(n);
        for (int i = 0; i < n; i++) {
            cin >> phone[i];
        }
        
        sort(phone.begin(), phone.end());
        
        bool isPrefix = false;
        for (int i = 1; i < n; i++) {
            if (phone[i - 1].length() >= phone[i].length()) continue;
            if (phone[i].substr(0, phone[i - 1].length()).compare(phone[i - 1]) == 0) {
                isPrefix = true;
                break;
            }
        }
        if (isPrefix) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
    return 0;
}

/*
 전화번호 목록이 주어질 때, 이 목록이 일관성이 있는지 없는지 구하는 프로그램을 작성
 전화번호 목록이 일관성을 유지하려면, 한 번호가 다른 번호의 접두어인 경우가 없어야 한다.
 
 주어진 전화번호 목록을 정렬하면 시간복잡도가 O(NlogN * 10)이므로 O(NlogN)이고, 앞 뒤 전화번호에 대해서만 접두어인 경우를 확인하는 방식으로 풀이 진행 
 */
