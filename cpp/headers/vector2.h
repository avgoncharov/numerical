#ifndef _AVG_VECTOR2_
#define _AVG_VECTOR2_

#define __AVG_CPP11__
#include"common.h"

namespace avg_matrix
{
	class Matrix2x2;

	// Вектр (строка / столбец) размерностью 2.
	class Vector2{
	public:
		Vector2();
		~Vector2();
		Vector2(const Vector2& source);
#ifdef __AVG_CPP11__
		Vector2(Vector2&& source);
		Vector2& operator=(Vector2&& source);
#endif
		Vector2& operator=(const Vector2& source);
		

		// Возвращает ссылку на элемент вектора (строки / столбца).
		double& operator()(int i);
		
		// Возвращает константную ссылку на элемент вектора (строки / столбца).
		const double& operator()(int i)const;
		
		// Умножает вектора (строку / столбеце) на вектор (строку / столбеце).
		friend double operator*(const Vector2& rhs, const Vector2& lhs);

		// Умножает вектор (строку / столбеце) на число.
		friend Vector2 operator*(double num, const Vector2& vec);

		// Сложение векторов.
		friend Vector2 operator+(const Vector2& lhs, const Vector2& rhs);

		// Умножает строку на матрицу.
		friend Vector2 operator*(const Vector2& vec, const Matrix2x2& matrix);

		// Умножает матрицу на столбец.
		friend Vector2 operator*(const Matrix2x2& matrix, const Vector2& vec);

		// Вывод вектора в поток.
		friend std::ostream& operator<<(std::ostream& os, const Vector2& vec);


	private:
		void createArrAndCopyFrom(const Vector2& source);
		double* _arr;
	};

	
}


#endif