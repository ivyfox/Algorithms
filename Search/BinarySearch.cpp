#include <iostream>
using namespace std;

int binary_search(int *arr, int n, int value)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == value) return mid;
        else if (arr[mid] > value) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}

// lower_bound() in std::<algorithm>
int lower_bound(int *arr, int n, int value)
{
    int low = 0;
    int high = n;
    int mid;

    while (low < high) {
        mid = (low + high) / 2;
        if (arr[mid] >= value) high = mid;
        else low = mid + 1;
    }

    return low;
}

// upper_bound() in std::<algorithm>
int upper_bound(int *arr, int n, int value)
{
    int low = 0;
    int high = n;
    int mid;

    while (low < high) {
        mid = (low + high) / 2;
        if (arr[mid] <= value) low = mid + 1;
        else high = mid;
    }

    return high;
}

int main()
{
    int n, arr[256], v;

    while (cin >> n) {
        for (int i=0; i<n; i++) cin >> arr[i];
        cin >> v;
        cout << binary_search(arr, n, v) << endl;
        cout << lower_bound(arr, n, v) << endl;
        cout << upper_bound(arr, n, v) << endl;
    }

    return 0;
}

