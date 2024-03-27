#include <iostream>
using namespace std;

void sort012(int *arr, int n)
{
    int count0 = 0, count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
    }
    fill_n(arr, count0, 0);
    fill_n(arr + count0, count0 + count1, 1);
    fill_n(arr + count0 + count1, n - (count0 + count1), 2);
}
int main()
{

    int arr[10] = {0, 0, 2, 2, 1, 0, 1, 2, 0, 2};

    sort012(arr, 10);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}