#include"../headers/matrix2x2.h"
#include<vector>
//--------------------------------------------------------------------------------------------------
avg_matrix::Matrix2x2::Matrix2x2(){
	createArr();
}

avg_matrix::Matrix2x2::Matrix2x2(const Matrix2x2& source)
{
	Copy(source);
}
avg_matrix::Matrix2x2& avg_matrix::Matrix2x2::operator=(const Matrix2x2& source)
{
	Copy(source);
	return *this;
}
avg_matrix::Matrix2x2::~Matrix2x2()
{
	deleteArr();
}

avg_matrix::Matrix2x2 avg_matrix::Matrix2x2::inverse()
{
	double det = this->det();
	Matrix2x2 minor = this->minor();
	Matrix2x2 t = minor.transponse();	

	return 1.0 / det * t;
}
avg_matrix::Matrix2x2 avg_matrix::Matrix2x2::transponse()
{
	Matrix2x2 result;
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; ++k)
			result(i, k) = _arr[k][i];
	}

	return result;
}

avg_matrix::Matrix2x2 avg_matrix::Matrix2x2::minor()
{
	Matrix2x2 result;;

	result(0,0) = _arr[1][1];
	result(0, 1) = -_arr[1][0];
	result(1, 0) = -_arr[0][1];
	result(1, 1) = _arr[0][0];

	return result;
}

double avg_matrix::Matrix2x2::det()
{
	return  _arr[0][0] * _arr[1][1] - _arr[1][0] * _arr[0][1];
}

double& avg_matrix::Matrix2x2::operator()(int i, int j)
{
	return _arr[i][j];
}

const double& avg_matrix::Matrix2x2::operator()(int i, int j) const
{
	return _arr[i][j];
}

avg_matrix::Matrix2x2 avg_matrix::operator*(double num, const avg_matrix::Matrix2x2& matrix)
{
	Matrix2x2 result;
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; ++k)
			result(i,k) = num * matrix(i,k);
	}

	return result;
}

void avg_matrix::Matrix2x2::Copy(const Matrix2x2& source)
{
	if (this == &source)
		return;

	createArr();

	for (int i = 0; i < 2; ++i) {
		for (int k = 0; k < 2; ++k)
			_arr[i][k] = source._arr[i][k];
	}
}

void avg_matrix::Matrix2x2::createArr()
{
	deleteArr();
	_arr = new double*[2];
	for (int i = 0; i < 2; ++i)
		_arr[i] = new double[2];
}

void avg_matrix::Matrix2x2::deleteArr()
{
	if (_arr == 0)
		return;

	for (int i = 0; i < 2; ++i)
		delete[] _arr[i];

	delete[] _arr;
	_arr = 0;
}

avg_matrix::Matrix2x2 avg_matrix::operator*(const  avg_matrix::Matrix2x2& lhs, const  avg_matrix::Matrix2x2& rhs)
{
	Matrix2x2 result;
	for (int i = 0; i < 2; ++i) {
		for (int k = 0; k < 2; ++k) {
			result(i, k) = 0;

			for (int m = 0; m < 2; ++m)
				result(i, k) += lhs(i, m) * rhs(m, k);
		}
	}

	return result;
}
