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
			result(i, k) = m(k,i);
	}

	return result;
}

avg_matrix::Matrix2x2 avg_matrix::minor(const Matrix2x2& m)
{
	Matrix2x2 result;;

	result(0, 0) = m(1,1);
	result(0, 1) = -m(1,0);
	result(1, 0) = -m(0,1);
	result(1, 1) = m(0, 0);

	return result;
}

double avg_matrix::det(const Matrix2x2& m)
{
	return  m(0, 0) * m(1, 1) - m(1, 0) * m(0,1);
}

double& avg_matrix::Matrix2x2::operator()(int i, int j)
{
	return _arr[i](j);
}

const double& avg_matrix::Matrix2x2::operator()(int i, int j) const
{
	return _arr[i](j);
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
			_arr[i](k) = source._arr[i](k);
	}
}

void avg_matrix::Matrix2x2::createArr()
{
	deleteArr();
	_arr = new Vector2[2];	
}

void avg_matrix::Matrix2x2::deleteArr()
{
	if (_arr == 0)
		return;

	delete[] _arr;
	_arr = 0;
}

avg_matrix::Matrix2x2 avg_matrix::operator*(const  avg_matrix::Matrix2x2& lhs, const  avg_matrix::Matrix2x2& rhs)
{
	Matrix2x2 result;
	for (int i = 0; i < 2; ++i) {
		for (int k = 0; k < 2; ++k) {			
			double s = 0;
			for (int m = 0; m < 2; ++m)
				s += lhs(i, m) * rhs(m, k);

			result(i, k) = s;
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
			s += vec(k)* matrix(k, i);
		
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
			s += matrix(i, k)*vec(k);

		result(i) = s;
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
	os << m._arr[0]<<std::endl;
	os << m._arr[1] << std::endl;

	return os;
}