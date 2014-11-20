#include<iostream>
#include"../headers/matrix2x2.h"
#include"../headers/vector2.h"

using namespace std;
using namespace avg_matrix;
void main()
{
	const int len = 2;
	Matrix2x2 m;
	m(0,0) = 1;
	m(0,1) = 2;
	m(1,0) = 3;
	m(1,1) = 4;
	
	//Проверяем определитель для матрицы 2x2.
	cout << m.det() << endl;
	cout << endl;
	//Проверяем минор для матрицы 2x2.
	Matrix2x2 minor = m.minor();
	for (int i = 0; i < len; ++i) {
		for (int k = 0; k < len; ++k)
			cout << minor(i,k) << " ";
		cout << endl;
	}


	//Проверяем транспонирование для матрицы 2x2.
	cout << endl;
	Matrix2x2 t = minor.transponse();
	for (int i = 0; i < len; ++i) {
		for (int k = 0; k < len; ++k)
			cout << t(i,k) << " ";
		cout << endl;
	}
	
	//Проверяем обратную матрицу для матрицы 2x2.
	cout << endl;
	Matrix2x2 rev = m.inverse();
	for (int i = 0; i < len; ++i) {
		for (int k = 0; k < len; ++k)
			cout << rev(i,k) << " ";
		cout << endl;
	}


	// Проверяем произведение матрицы на обратную.
	cout << endl;
	Matrix2x2 res = rev * m;
	for (int i = 0; i < len; ++i) {
		for (int k = 0; k < len; ++k)
			cout << res(i,k) << " ";
		cout << endl;
	}

	//Проверяем умножение вектора на матрицу.
	Vector2 vec;
	vec(0) = 1;
	vec(1) = 2;
	
	cout << endl;
	Vector2 vecR = vec * m;
	for (int i = 0; i < len; ++i) {
		cout << vecR(i) << " ";		
	}

	//Проверяем умножение матрицы на вектор.
	cout << endl;
	Vector2 vecR2 = m * vec;
	for (int i = 0; i < len; ++i) {
		cout << vecR2(i) << " ";
	}

	//Проверяем умножение матрицы на множество вектор.
	Vector2 vec2;
	vec2(0) = 2;
	vec2(1) = 1;

	Vector2 arr[2] = { vec, vec2 };

	std::vector<Vector2> resultVec = multiply(m, arr, arr + 2);
	int size = resultVec.size();
	cout << endl;
	cout << "------------------------";
	cout << endl;
	for (int k = 0; k < size; ++k) {
		for (int i = 0; i < len; ++i) {
			cout << resultVec[k](i) << " ";
		}
		cout << endl;
	}
}