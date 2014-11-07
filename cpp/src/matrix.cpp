#include"../headers/matrix.h"
double** avg_matrix::MatrixOperations::transpose(double* matrix[], int row_count, int column_count){
	double** result = new double*[column_count];
	for (int i = 0; i < column_count; ++i)
		result[i] = new double[row_count];

	for (int i = 0; i < row_count; i++) {
		for (int k = 0; k < column_count; k++) {
			result[k][i] = matrix[i][k];
		}
	}

	return result;
}

double** avg_matrix::MatrixOperations::multiple(double* lhs[], double* rhs[], int i, int k, int j){
	double** result = new double*[i];
	for (int u = 0; u < i; ++u)
		result[u] = new double[j];

	for (int u = 0; u < i; ++u) {
		for (int m = 0; m < j; ++m) {
			result[u][m] = 0;

			for (int h = 0; h < k; ++h)
				result[u][m] += lhs[u][h] * rhs[h][m];
		}
	}

	return result;
}

