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

	/*Vector2* vvv = new Vector2[100000];
	for (int i = 0; i < 100000; ++i) {
		Vector2 buf = 10 * vec;
		Matrix2x2 bufM = 10 * m;
		vvv[i] = bufM * buf;
	}

	cout << vvv[100000 - 1]<<endl;*/

	cout << "----------------------------------------" << endl;

	Vector2 lhs;
	lhs(0) = 1;
	lhs(1) = 2;
	Vector2 rhs;
	rhs(0) = 3;
	rhs(1) = 4;

	cout << (lhs + rhs) << endl;
	cout << (lhs - rhs) << endl;


	Matrix2x2 mlhs;
	mlhs(0, 0) = 0;
	mlhs(0, 1) = 1;
	mlhs(1, 0) = 2;
	mlhs(1, 1) = 3;

	Matrix2x2 mrhs;
	mrhs(0, 0) = 0;
	mrhs(0, 1) = 1;
	mrhs(1, 0) = 2;
	mrhs(1, 1) = 3;

	cout << (mlhs + mrhs) << endl;
	cout << (mlhs - mrhs) << endl;


	cout << "Ok";
	
}