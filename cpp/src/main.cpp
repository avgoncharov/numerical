#include<iostream>
#include"../headers/matrix.h"

using namespace std;
void main()
{
	const int len = 2;
	double** matrix = new double*[len];
	for (int i = 0; i < len; ++i)
		matrix[i] = new double[len];

	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	matrix[1][1] = 4;

	//ѕровер¤ем определитель дл¤ матрицы 2x2.
	cout << avg_matrix::det2x2(matrix) << endl;
	cout << endl;

	//ѕровер¤ем минор дл¤ матрицы 2x2.
	double** minor = avg_matrix::minor2x2(matrix);
	for (int i = 0; i < len; ++i) {
		for (int k = 0; k < len; ++k)
			cout << minor[i][k] << " ";
		cout << endl;
	}

	//ѕровер¤ем транспонирование дл¤ матрицы 2x2.
	cout << endl;
	double** t = avg_matrix::transpnse2x2(minor);
	for (int i = 0; i < len; ++i) {
		for (int k = 0; k < len; ++k)
			cout << t[i][k] << " ";
		cout << endl;
	}
	avg_matrix::deleteNxM(minor, 2);
	avg_matrix::deleteNxM(t, 2);

	//ѕровер¤ем обратную матрицу дл¤ матрицы 2x2.
	cout << endl;
	double** rev = avg_matrix::inverse2x2(matrix);
	for (int i = 0; i < len; ++i) {
		for (int k = 0; k < len; ++k)
			cout << rev[i][k] << " ";
		cout << endl;
	}

	// ѕровер¤ем произведение матрицы на обратную.
	cout << endl;
	double** res = avg_matrix::multiple(rev, matrix, 2, 2, 2);
	for (int i = 0; i < len; ++i) {
		for (int k = 0; k < len; ++k)
			cout << res[i][k] << " ";
		cout << endl;
	}

	// ѕровер¤ем произведение матрицы 2х2 на вектор 2.
	cout << endl;
	double* v = new double[2]{1,2};
	double* vr = avg_matrix::multipleM2x2ToV2(matrix, v);
	for (int i = 0; i < 2; ++i)
		cout << vr[i] << " ";
	cout << endl;

	// ѕровер¤ем произведение матрицы 2х2 на массив 3х вектор 2.
	double** arrV = new double*[3];
	for (int i = 0; i < 3; ++i)
		arrV[i] = new double[2]{1, (double)i};

	cout << endl;
	cout << endl;
	double** arrVres = avg_matrix::multipleM2x2ToArrOfV2(matrix, arrV, arrV + 3);
	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 2; ++k)
			cout << arrVres[i][k] << " ";
		cout << endl;
	}
}