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
	cout << det(m) << endl;
	cout << endl;
	//Проверяем минор для матрицы 2x2.
	Matrix2x2 minor = avg_matrix::minor(m);
	cout << minor << endl;
	
	//Проверяем транспонирование для матрицы 2x2.	
	Matrix2x2 t = transponse(minor);
	cout << t << endl;
	
	//Проверяем обратную матрицу для матрицы 2x2.	
	Matrix2x2 rev = inverse(m);
	cout << rev << endl;
	
	// Проверяем произведение матрицы на обратную.
	Matrix2x2 res = rev * m;
	cout << res;
	
	//Проверяем умножение вектора на матрицу.
	Vector2 vec;
	vec(0) = 1;
	vec(1) = 2;
		
	Vector2 vecR = vec * m;
	cout << vecR << endl;
	
	//Проверяем умножение матрицы на вектор.	
	Vector2 vecR2 = m * vec;
	cout << vecR2 << endl;
	
	//Проверяем умножение матрицы на множество вектор.
	Vector2 vec2;
	vec2(0) = 2;
	vec2(1) = 1;

	Vector2 arr[2] = { vec, vec2 };

	std::vector<Vector2> resultVec = multiply(m, arr, arr + 2);
	int size = resultVec.size();	
	cout << "------------------------";
	cout << endl;	
	for (int k = 0; k < size; ++k) 
		cout << resultVec[k]<<endl;
}