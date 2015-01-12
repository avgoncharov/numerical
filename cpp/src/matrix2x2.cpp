#include"../headers/matrix2x2.h"
#include<vector>
//--------------------------------------------------------------------------------------------------
avg_matrix::Matrix2x2::Matrix2x2(){
	_arr = 0;
	createArr();
}

avg_matrix::Matrix2x2::Matrix2x2(const Matrix2x2& source)
{
	_arr = 0;
	Copy(source);
}

#ifdef __AVG_CPP11__
avg_matrix::Matrix2x2::Matrix2x2(Matrix2x2&& source)
{
	_arr = source._arr;
	source._arr = 0;
}

avg_matrix::Matrix2x2& avg_matrix::Matrix2x2::operator=(Matrix2x2&& source)
{
	if (this == &source)
		return *this;
	
	deleteArr();

	_arr = source._arr;
	source._arr = 0;

	return *this;
}
#endif

avg_matrix::Matrix2x2& avg_matrix::Matrix2x2::operator=(const Matrix2x2& source)
{
	Copy(source);
	return *this;
}
avg_matrix::Matrix2x2::~Matrix2x2()
{
	deleteArr();
}

avg_matrix::Matrix2x2 avg_matrix::inverse(const Matrix2x2& m)
{
	double d = det(m);
	Matrix2x2 mnr = minor(m);
	Matrix2x2 t = transponse(mnr);

	return 1.0 / d * t;
}
avg_matrix::Matrix2x2 avg_matrix::transponse(const Matrix2x2& m)
{
	Matrix2x2 result;
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; ++k)
			result._arr[i][k] = m._arr[k][i];
	}

	return result;
}

avg_matrix::Matrix2x2 avg_matrix::minor(const Matrix2x2& m)
{
	Matrix2x2 result;

	result._arr[0][0] = m._arr[1][1];
	result._arr[0][1] = -m._arr[1][0];
	result._arr[1][0] = -m._arr[0][1];
	result._arr[1][1] = m._arr[0][0];

	return result;
}

double avg_matrix::det(const Matrix2x2& m)
{
	return  m._arr[0][0] * m._arr[1][1] - m._arr[1][0] * m._arr[0][1];
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
			result._arr[i][k] = num * matrix._arr[i][k];
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
	_arr[0] = new double[2];
	_arr[1] = new double[2];
}

void avg_matrix::Matrix2x2::deleteArr()
{
	if (_arr == 0)
		return;

	delete[] _arr[0];
	delete[] _arr[1];
	delete[] _arr;

	_arr = 0;
}

avg_matrix::Matrix2x2 avg_matrix::operator*(const  avg_matrix::Matrix2x2& lhs, const  avg_matrix::Matrix2x2& rhs)
{
	Matrix2x2 result;

	Matrix2x2 buf = transponse(rhs);

	for (int i = 0; i < 2; ++i) {
		for (int k = 0; k < 2; ++k) {			
			double s = 0;
			for (int m = 0; m < 2; ++m)
				s += lhs._arr[i][m] * rhs._arr[m][k];

			result._arr[i][k] = s;
		}
	}

	return result;
}

avg_matrix::Vector2 avg_matrix::operator*(const Vector2& vec, const Matrix2x2& matrix)
{
	Vector2 result;

	for (int i = 0; i < 2; ++i) {		
		double s = 0;
		for (int k = 0; k < 2; ++k) 
			s += vec._arr[k] * matrix._arr[k][i];
		
		result(i) = s;
	}

	return result;

}
avg_matrix::Vector2 avg_matrix::operator*(const Matrix2x2& matrix, const Vector2& vec)
{
	Vector2 result;

	for (int i = 0; i < 2; ++i) {
		double s = 0;
		for (int k = 0; k < 2; ++k) 
			s += matrix._arr[i][k] * vec._arr[k];

		result(i) = s;
	}

	return result;
}

avg_matrix::Matrix2x2 avg_matrix::operator+(const Matrix2x2&lhs, const Matrix2x2& rhs)
{
	Matrix2x2 result;

	for (int i = 0; i < 2; ++i) {
		for (int k = 0; k < 2; ++k)
			result._arr[i][k] = lhs._arr[i][k] + rhs._arr[i][k];
	}

	return result;
}

avg_matrix::Matrix2x2 avg_matrix::operator-(const Matrix2x2&lhs, const Matrix2x2& rhs)
{
	Matrix2x2 result;

	for (int i = 0; i < 2; ++i) {
		for (int k = 0; k < 2; ++k)
			result._arr[i][k] = lhs._arr[i][k] - rhs._arr[i][k];
	}

	return result;
}

std::vector<avg_matrix::Vector2> avg_matrix::multiply(const Matrix2x2& matrix, const Vector2* begin, const Vector2* end)
{
	std::vector<Vector2> result;

	for (const Vector2* itr = begin; itr != end; ++itr)
		result.push_back(matrix*(*itr));

	return result;
}

std::ostream& avg_matrix::operator<<(std::ostream& os, const Matrix2x2& m)
{
	os << m._arr[0][0] <<" "<< m._arr[0][1] << std::endl;
	os << m._arr[1][0] << " " << m._arr[1][1] << std::endl;

	return os;
}

avg_matrix::Matrix2x2 avg_matrix::mult_clmn_on_row(const avg_matrix::Vector2& clmn, const avg_matrix::Vector2& row)
{
	Matrix2x2 result;

	for (int i = 0; i < 2; ++i) {
		for (int k = 0; k < 2; ++k)
			result._arr[i][k] = clmn(i) * row(k);
	}

	return result;
}