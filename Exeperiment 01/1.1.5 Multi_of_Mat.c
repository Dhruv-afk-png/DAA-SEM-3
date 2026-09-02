/*Write a program to multiply two matrices A and B. The program should read their dimensions and elements, check whether matrix multiplication is possible, and display the resulting 
product matrix.*/


#include <stdio.h>
int main() {
	int m, n, r, p;
	scanf("%d %d", &m, &n);
	int A[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	scanf("%d %d", &r, &p);
	if (n != r) {
		printf("Invalid input");
		return 0;
	}
	int B[r][p], C[m][p];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < p; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			C[i][j] = 0;
			for (int k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			printf("%d ", C[i][j]);
			if (j != p - 1)
				printf("");
		}
		printf("\n");
	}
	return 0;
}
