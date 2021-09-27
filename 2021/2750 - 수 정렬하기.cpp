#include <iostream>
using namespace std;
int main() {
    int N;
    int num[1000] = { 0 };
    int tmp;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    for (int i = N; i > 1; i--)
        for (int j = 0; j + 1 < i; j++)
            if (num[j] > num[j + 1])
            {
                tmp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = tmp;
            }
    for (int i = 0; i < N; i++)
        cout << num[i] << '\n';
}