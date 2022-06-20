//
//  최대공약수와 최소공배수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/21.
//

#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b){
    while(b){
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    int gcd = GCD(n, m);
    answer.push_back(gcd);
    answer.push_back(n * m / gcd);
    return answer;
}
