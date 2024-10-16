#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int countOrderedPairsLiverpool(int A[], int n) {
    int count = 0;
    for (int v = 0; v < n; v++) {
        for (int p = v + 1; p < n; p++) {
            if (A[v] < A[p]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int A[] = {4, 15, 10, 1, 3};
    int n = 5;
    std::cout << countOrderedPairsLiverpool(A, n) << std::endl;

    int B[] = {4, 5, 6, 7, 8};
    int v = 5;
    std::cout << countOrderedPairsLiverpool(B, v) << std::endl;

    int C[] = {80, 70, 60, 50, 40};
    int q = 5;
    std::cout << countOrderedPairsLiverpool(C, q) << std::endl;

    return 0;
}