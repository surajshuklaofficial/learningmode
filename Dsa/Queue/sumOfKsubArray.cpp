#include <iostream>
#include <queue>
#include <climits>
using namespace std;

// Method 1
// int Max(int *arr, int size) {
//     int mini = INT_MIN;

//     for (int i = 0; i < size; i++) mini = max(mini, arr[i]);

//     return mini;
// }

// int Min(int *arr, int size) {
//     int maxi = INT_MAX;
//     for (int i = 0; i < size; i++) maxi = min(maxi, arr[i]);

//     return maxi;
// }
// int SumOfKsubArray(int *arr, int size, int k) {

//     int sum = 0;

//     for (int i = 0; i <= size - k; i++) {
//         sum += Min(arr + i, k) + Max(arr + i, k);
//     }

//     return sum;
// }

// Method 2: (Optimized)
int SumOfKsubArray(int arr[], int n, int k)
{
    int sum = 0;
    deque<int> S(k), G(k);

    // Process first window of size K
    int i = 0;
    for (i = 0; i < k; i++)
    {
        while ((!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back();

        while ((!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back();

        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }

    // Process rest of the Array elements
    for (; i < n; i++)
    {
        sum += arr[S.front()] + arr[G.front()];

        // removal
        while (!S.empty() && S.front() <= i - k)
            S.pop_front();
        while (!G.empty() && G.front() <= i - k)
            G.pop_front();

        // addition
        while ((!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back();

        while ((!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back();

        G.push_back(i);
        S.push_back(i);
    }

    // Sum of minimum and maximum element of last window
    sum += arr[S.front()] + arr[G.front()];

    return sum;
}

int main()
{

    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int N = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << SumOfKsubArray(arr, N, k);
    return 0;
}