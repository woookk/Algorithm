//
//  heap_test.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/06.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int heap[100005];
int sz = 0;

void push(int x){
    heap[++sz] = x;
    int idx = sz;
    while(idx != 1){
        int parent = idx / 2;
        if(heap[parent] <= heap[idx]) break;
        swap(heap[parent], heap[idx]);
        idx = parent;
    }
}

int top(){
    return heap[1];
}

void pop() {
    heap[1] = heap[sz--];
    int idx = 1;
    while(2 * idx <= sz){
        int left_child = 2 * idx, right_child = 2 * idx + 1;
        int min_child = left_child;
        if(right_child <= sz && heap[right_child] < heap[left_child])
            min_child = right_child;
        if(heap[idx] <= heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }
}

void test() {
    push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
    cout << top() << '\n'; // 2
    pop(); // {10, 5, 9}
    pop(); // {10, 9}
    cout << top() << '\n'; // 9
    push(5); push(15); // {10, 9, 5, 15}
    cout << top() << '\n'; // 5
    pop(); // {10, 9, 15}
    cout << top() << '\n'; // 9
}

int main(void) {
    FASTIO
    test();
}
