#include"../headers/matrix.h"
#include<vector>

double** avg_matrix::createNxM(int n, int m)
{
	if (n < 0 || m < 0)
		return 0;

	double** result = new double*[n];
	for (int i = 0; i < n; ++i)
		result[i] = new double[m];

	return result;
};

double** avg_matrix::createNxN(int n)
{
	return createNxM(n, n);
};

void avg_matrix::deleteNxM(double* m[], int row_num)
{
	if (row_num < 0 || !m)
		throw 312;

	for (int i = 0; i < row_num; ++i)
		delete[] m[i];

	delete[] m;
};

double** avg_matrix::transpose(const double* const* matrix, int row_count, int column_count){
	double** result = createNxM(column_count, row_count);

	for (int i = 0; i < row_count; i++) {
		for (int k = 0; k < column_count; k++) {
			result[k][i] = matrix[i][k];
		}
	}

	return result;
}

double** avg_matrix::multiple(const double* const* lhs, const double* const* rhs, int i, int k, int j){
	double** result = createNxM(i, j);

	for (int u = 0; u < i; ++u) {
		for (int m = 0; m < j; ++m) {
			result[u][m] = 0;

			for (int h = 0; h < k; ++h)
				result[u][m] += lhs[u][h] * rhs[h][m];
		}
	}

	return result;
}

double avg_matrix::det2x2(const double* const* m)
{
	return m[0][0] * m[1][1] - m[1][0] * m[0][1];
}

double** avg_matrix::minor2x2(const double* const* m)
{
	double** result = createNxN(2);

	result[0][0] = m[1][1];
	result[0][1] = - m[1][0];
	result[1][0] = - m[0][1];
	result[1][1] = m[0][0];

	return result;
}

double** avg_matrix::transpnse2x2(const double* const* m)
{
	return transpose(m, 2, 2);
}

double** avg_matrix::inverse2x2(const double* const* m){
	double det = det2x2(m);
	double** minor = minor2x2(m);
	double** t = transpnse2x2(minor);
	deleteNxM(minor, 2);

	double** result = createNxN(2);
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; ++k)
			result[i][k] = 1.0 / det * t[i][k];
	}
	
	deleteNxM(t, 2);

	return result;
}

double* avg_matrix::multipleM2x2ToV2(const double* const* m, const double v[])
{
	double* result = new double[2];

	for (int i = 0; i < 2; ++i)  {
		result[i] = 0;
		for (int k = 0; k < 2; ++k) {
			result[i] += m[i][k] * v[k];
		}
	}

	return result;
}

double** avg_matrix::multipleM2x2ToArrOfV2(const double* const* m, const double* const* begin, const double* const* end)
{
	std::vector<double*> buf;
	for (const double* const* itr = begin; itr != end; ++itr) 
		buf.push_back(multipleM2x2ToV2(m, *itr));

	const int size = buf.size();
	double** result = new double*[size];
	for (int i = 0; i < size; ++i)
		result[i] = buf[i];

	return result;
}
