#ifndef _AVG_MATRIX2X2_
#define _AVG_MATRIX2X2_
#include"vector2.h"

namespace avg_matrix
{	
	//Квадратная матрица размером 2х2.
	class Matrix2x2{
	public:
		Matrix2x2();
		Matrix2x2(const Matrix2x2& source);
#ifdef __AVG_CPP11__
		Matrix2x2(Matrix2x2&& source);
		Matrix2x2& operator=(Matrix2x2&& source);
#endif

		Matrix2x2& operator=(const Matrix2x2& source);
		~Matrix2x2();		

		// Возвращает ссылку на (i,j) элемент матрицы.
		double& operator()(int i, int j);
		
		// Возвращает константную ссылку на (i,j) элемент матрицы.
		const double& operator()(int i, int j) const;

		// Вывод вектора в поток.
		friend std::ostream& operator<<(std::ostream& os, const Matrix2x2& m);

		// Возвращает обратную матрицу.
		friend Matrix2x2 inverse(const Matrix2x2& m);

		// Возвращает транспонированную матрицу.
		friend Matrix2x2 transponse(const Matrix2x2& m);

		// Возвращает минор матрицы.
		friend Matrix2x2 minor(const Matrix2x2& m);

		// Возвращает определитель матрицы.
		friend double det(const Matrix2x2& m);

		// Умножает матрицу на число.
		friend Matrix2x2 operator*(double num, const Matrix2x2& matrix);

		// Выполняет произведения квадратных матриц.
		friend Matrix2x2 operator*(const Matrix2x2& lhs, const Matrix2x2& rhs);

		// Умножает строку на матрицу.
		friend Vector2 operator*(const Vector2& vec, const Matrix2x2& matrix);

		// Умножает матрицу на столбец.
		friend Vector2 operator*(const Matrix2x2& matrix, const Vector2& vec);

		// Умножает матрицу на множество столбцов ограниченных итератором begin и end. end - указывает на память сразу за последним элементом.
		friend std::vector<Vector2> multiply(const Matrix2x2& matrix, const Vector2* begin, const Vector2* end);

	private:
		void Copy(const Matrix2x2& source);
		void createArr();
		void deleteArr();

		double** _arr;
	};

	
	
}
#endif