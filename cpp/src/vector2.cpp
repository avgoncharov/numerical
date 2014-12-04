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

#ifdef __AVG_CPP11__
avg_matrix::Vector2::Vector2(Vector2&& source)
{	
	_arr = source._arr;

	source._arr = 0;
}

avg_matrix::Vector2& avg_matrix::Vector2::operator=(Vector2&& source)
{
	if(this == &source)	
		return *this;

	if (_arr != 0)
		delete[] _arr;
	
	_arr = source._arr;
	source._arr = 0;

	return *this;
}
#endif

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
	result(0) = num * vec._arr[0];
	result(1) = num * vec._arr[1];

	return result;
}

double avg_matrix::operator*(const Vector2& rhs, const Vector2& lhs)
{
	return rhs._arr[0] * lhs._arr[0] + rhs._arr[1] * lhs._arr[1];
}

// Сложение векторов.
avg_matrix::Vector2 avg_matrix::operator+(const Vector2& lhs, const Vector2& rhs)
{
	Vector2 result;

	for (int i = 0; i < 2; ++i)
		result(i) = lhs._arr[i] + rhs._arr[i];

	return result;
}
//Вычитание векторов.
avg_matrix::Vector2 avg_matrix::operator-(const Vector2& lhs, const Vector2& rhs)
{
	Vector2 result;

	for (int i = 0; i < 2; ++i)
		result(i) = lhs._arr[i] - rhs._arr[i];

	return result;
}


// Вывод вектора в поток.
std::ostream& avg_matrix::operator<<(std::ostream& os, const Vector2& vec)
{
	os << vec._arr[0] << " " << vec._arr[1];
	return os;
}