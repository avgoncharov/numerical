#ifndef _AVG_VECTOR2_
#define _AVG_VECTOR2_

#define __AVG_CPP11__
#include"common.h"

namespace avg_matrix
{
	// Вектр (строка / столбец) размерностью 2.
	class Vector2{
	public:
		Vector2();
		~Vector2();
		Vector2(const Vector2& source);
#ifdef __AVG_CPP11__
		Vector2(Vector2&& source);
#endif
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

	// Сложение векторов.
	Vector2 operator+(const Vector2& lhs, const Vector2& rhs);

	// Вывод вектора в поток.
	std::ostream& operator<<(std::ostream& os, const Vector2& vec);
}


#endif