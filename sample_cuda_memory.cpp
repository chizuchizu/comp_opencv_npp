#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <npp.h>
using namespace std;


int main(void) {
    int N = 1024;
    int *a, *b, *c, *a_d, *b_d, *c_d;
    // ホスト側
    cudaMallocHost(&a, N * sizeof(int));
	  cudaMallocHost(&b, N * sizeof(int));
    // デバイス側
    cudaMalloc(&a_d, N * sizeof(int));

    for (int i = 0; i < N; i++){
        a[i] = i;
    }

    cudaMemcpy(a_d, a, N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(b, a_d, N * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < N; i++) cout << b[i] << ", ";
    cout << endl;

    cudaFree(a);
    cudaFree(a_d);
    cudaFree(b);

    return 0;
}
