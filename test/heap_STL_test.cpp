//
//  heap_test.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/02.
//

#include <iostream>
#include <queue>
using namespace std;

int main(void){
    priority_queue<int> pq; // 최대 힙
//    priority_queue<int, vector<int>, greater<int>> pq; //최소 힙
    pq.push(10); pq.push(2); pq.push(5); pq.push(9); // {10, 2, 5, 9}
    cout << pq.top() << '\n'; // 10
    pq.pop(); // {2, 5, 9}
    cout << pq.size() << '\n'; // 3
    if(pq.empty()) cout << "PQ is empty\n";
    else cout << "PQ is not empty\n";
    pq.pop(); // {2, 5}
    cout << pq.top() << '\n'; // 5
    pq.push(5); pq.push(15); // {2, 5, 5, 15}
    cout << pq.top() << '\n'; // 15
    
    //test 2
    priority_queue<pair<int, string>> pq2;
    pq2.push({1, "first"});
    pq2.push({3, "second"});
    pq2.push({2, "third"});
    cout << pq2.top().first << " " << pq2.top().second << "\n";
    pq2.pop();
    cout << pq2.top().first << " " << pq2.top().second << "\n";
    
    cout << "\n";
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq3;
    pq3.push({3, "first"});
    pq3.push({1, "second"});
    pq3.push({2, "third"});
    cout << pq3.top().first << " " << pq3.top().second << "\n";
    pq3.pop();
    cout << pq3.top().first << " " << pq3.top().second << "\n";
}
