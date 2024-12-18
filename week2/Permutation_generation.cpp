v#include <bits/stdc++.h>
using namespace std;

bool next_Permutation(int a[], int n) {
    int j = n - 2;
    while (j >= 0 && a[j] > a[j + 1]) j--;
    if (j == -1) return false;
    int k = n - 1;
    while (a[j] > a[k]) k--;
    swap(a[j], a[k]);
    int r = n - 1, l = j + 1;
    while (r > l) {
        swap(a[r], a[l]);
        r--;
        l++;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    do {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } while (next_Permutation(a, n));
    return 0;
}
