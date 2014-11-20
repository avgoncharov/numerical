#ifndef _AVG_VECTOR2_
#define _AVG_VECTOR2_
#include"matrix2x2.h"
#include<vector>
namespace avg_matrix
{
	// Вектр (строка / столбец) размерностью 2.
	class Vector2{
	public:
		Vector2();
		~Vector2();
		Vector2(const Vector2& source);
		Vector2& operator=(const Vector2& source);

		// Возвращает ссылку на элемент вектора (строки / столбца).
		double& operator()(int i);
		
		// Возвращает константную ссылку на элемент вектора (строки / столбца).
		const double& operator()(int i)const;

	private:
		void createArrAndCopyFrom(const Vector2& source);
		double* _arr;
	};

	// Умножает вектор (строку / столбеце) на число.
	Vector2 operator*(double num, const Vector2& vec);

	// Умножает строку на матрицу.
	Vector2 operator*(const Vector2& vec, const Matrix2x2& matrix);

	// Умножает матрицу на столбец.
	Vector2 operator*(const Matrix2x2& matrix, const Vector2& vec);

	// Умножает матрицу на множество столбцов ограниченных итератором begin и end. end - указывает на память сразу за последним элементом.
	std::vector<Vector2> multiply(const Matrix2x2& matrix, const Vector2* begin, const Vector2* end);

}
#endif