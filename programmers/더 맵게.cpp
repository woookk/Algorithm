//
//  더 맵게.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/30.
//

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }
    int answer = 0;

    while(pq.size() > 1 && pq.top() < K){
        int elem1, elem2, newelem;
        elem1 = pq.top();
        pq.pop();
        elem2 = pq.top();
        pq.pop();
        newelem = elem1 + 2 * elem2;
        pq.push(newelem);
        answer++;
    }
    if(pq.top() < K) return -1;
    return answer;
}
