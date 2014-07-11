#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// Solution 1
void dfs(int *input, int *output, bool *used, int n, int d)
{
    if (d == n) {
        for (int i=0; i<n; i++) cout << output[i] << ",";
        cout << endl;
        return;
    }

    for (int i=0; i<n; i++) {
        if (used[i]) continue;
        if (i > 0 && input[i] == input[i - 1] && used[i - 1]) continue; // remove duplications
        used[i] = true;
        output[d] = input[i];
        dfs(input, output, used, n, d + 1);
        used[i] = false;
    }
}
void perm1(int *input, int n)
{
    int *output = new int[n];
    bool *used = new bool[n];
    memset(output, 0, sizeof(output));
    memset(used, 0, sizeof(used));
    sort(input, input + n); // guarantee lexigraphical order
    dfs(input, output, used, n, 0);
    delete []output;
    delete []used;
}

// Solution 2
void swap(int *arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
void perm2(int *arr, int n, int k)
{
    if (k == n) {
        for (int i=0; i<n; i++) cout << arr[i] << ", ";
        cout << endl;
        return;
    }

    for (int i=k; i<n; i++) {
        swap(arr, k, i);
        perm2(arr, n, k + 1);
        swap(arr, i, k);
    }
}

// Solution 3
bool next_perm(int *arr, int n)
{
    int i;
    for (i = n - 2; i >= 0; i --) {
        if (arr[i] < arr[i + 1]) break;
    }

    if (i < 0) return false;

    int j;
    for (j = n - 1; j > i; j --) {
        if (arr[j] > arr[i]) break;
    }

    swap(arr, i, j);
    reverse(arr + i + 1, arr + n);
    return true;
}
void perm3(int *arr, int n)
{
    sort(arr, arr + n);
    do {
        for (int i = 0; i < n; i ++) cout << arr[i] << ",";
        cout << endl;
    } while (next_perm(arr, n));
}

void permutation(int *input, int n)
{
    //perm1(input, n);
    //perm2(input, n, 0);
    perm3(input, n);
}

int main()
{
    int n, arr[100];
    while (cin >> n) {
        for (int i=0; i<n; i++) cin >> arr[i];
        permutation(arr, n);
    }

    return 0;
}
