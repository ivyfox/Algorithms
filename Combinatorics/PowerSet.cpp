#include <iostream>
using namespace std;

void dfs(int *input, int n, int *output, int m, int d)
{
    if (d == n) {
        cout << "{ ";
        for (int i = 0; i < m; i ++) cout << output[i] << ", ";
        cout << "}" << endl;
        return;
    }

    output[m] = input[d];
    dfs(input, n, output, m + 1, d + 1);
    dfs(input, n, output, m, d + 1);
}

void powerSet(int *input, int n)
{
    int *output = new int[n];
    dfs(input, n, output, 0, 0);
    delete []output;
}

int main()
{
    int n;
    int arr[100];

    while (cin >> n) {
        for (int i=0; i<n; i++) cin >> arr[i];
        powerSet(arr, n);
    }

    return 0;
}
