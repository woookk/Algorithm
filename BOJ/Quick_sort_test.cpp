//
//  Quick_sort_test.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/04.
//

#include <iostream>
#include <cstdlib>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define SIZE 25

int arr[1000001];

void quick_sort(int st, int end){
    if(end <= st + 1) return;
    int pivot = arr[st];
    int l = st + 1;
    int r = end - 1;
    while(1){
        while(l <= r && arr[l] <= pivot) l++;
        while(l <= r && arr[r] >= pivot) r--;
        if(l > r) break;
        swap(arr[l], arr[r]);
    }
    swap(arr[st], arr[r]);
    quick_sort(st, r);
    quick_sort(r + 1, end);
}

void print(int *a, int N){
    for(int i = 0; i < N; i++){
        printf("%d ", *(a + i));
    }
    printf("\n");
}

int main(){
    FASTIO;
    srand((unsigned int)time(NULL));
    for(int i = 0; i < SIZE; i++){
        *(arr + i) = rand() % 100 + 1;
    }
    
    print(arr, SIZE);
    quick_sort(0, SIZE);
    print(arr, SIZE);
}
