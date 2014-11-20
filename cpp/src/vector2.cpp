#include"../headers/vector2.h"

avg_matrix::Vector2::Vector2()
{
	_arr = new double[2];
}
avg_matrix::Vector2::~Vector2()
{
	delete[] _arr;
}

void avg_matrix::Vector2::createArrAndCopyFrom(const Vector2& source)
{
	if (_arr != 0)
		delete[] _arr;

	_arr = new double[2];

	_arr[0] = source._arr[0];
	_arr[1] = source._arr[1];
}

avg_matrix::Vector2::Vector2(const Vector2& source)
{
	_arr = 0;
	createArrAndCopyFrom(source);
}
avg_matrix::Vector2& avg_matrix::Vector2::operator=(const Vector2& source)
{
	if (this == &source)
		return *this;
	
	createArrAndCopyFrom(source);
	
	return *this;
}

double& avg_matrix::Vector2::operator()(int i)
{
	return _arr[i];
}
const double& avg_matrix::Vector2::operator()(int i)const
{
	return _arr[i];
}

avg_matrix::Vector2 avg_matrix::operator*(double num, const avg_matrix::Vector2& vec)
{
	Vector2 result;
	result(0) = num * vec(0);
	result(1) = num * vec(1);

	return result;
}

avg_matrix::Vector2 avg_matrix::operator*(const Vector2& vec, const Matrix2x2& matrix)
{
	Vector2 result;

	for (int i = 0; i < 2; ++i) {
		result(i) = 0;

		for (int k = 0; k < 2; ++k) {
			result(i) += vec(k)* matrix(k, i);
		}
	}

	return result;

}
avg_matrix::Vector2 avg_matrix::operator*(const Matrix2x2& matrix, const Vector2& vec)
{
	Vector2 result;
	
	for (int i = 0; i < 2; ++i) {
		result(i) = 0;

		for (int k = 0; k < 2; ++k) {
			result(i) += matrix(i, k)*vec(k);
		}
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