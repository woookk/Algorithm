#include<iostream>
#include<algorithm>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, A[100000], num;

bool BinarySearch(int* arr, int len, int key) {
    int start = 0;
    int end = len - 1;
    int mid;

    while (end - start >= 0) {
        mid = (start + end) / 2;

        if (arr[mid] == key) {
            return true;
        }
        else if (arr[mid] > key) {
            end = mid - 1;
        }
        else start = mid + 1;
    }
    return false;
}
int main() {
    FASTIO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A + N);
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> num;
        cout << BinarySearch(A, N, num) << "\n";
    }
    return 0;
}