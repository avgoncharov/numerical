#ifndef _AVG_MATRIX2X2_
#define _AVG_MATRIX2X2_

namespace avg_matrix
{	
	//Квадратная матрица размером 2х2.
	class Matrix2x2{
	public:
		Matrix2x2();
		Matrix2x2(const Matrix2x2& source);
		Matrix2x2& operator=(const Matrix2x2& source);
		~Matrix2x2();

		// Возвращает обратную матрицу.
		Matrix2x2 inverse();

		// Возвращает транспонированную матрицу.
		Matrix2x2 transponse();

		// Возвращает минор матрицы.
		Matrix2x2 minor();

		// Возвращает определитель матрицы.
		double det();

		// Возвращает ссылку на (i,j) элемент матрицы.
		double& operator()(int i, int j);
		
		// Возвращает константную ссылку на (i,j) элемент матрицы.
		const double& operator()(int i, int j) const;
	private:
		void Copy(const Matrix2x2& source);
		void createArr();
		void deleteArr();

		double** _arr;
	};

	// Умножает матрицу на число.
	Matrix2x2 operator*(double num, const Matrix2x2& matrix);

	// Выполняет произведения квадратных матриц.
	Matrix2x2 operator*(const Matrix2x2& lhs, const Matrix2x2& rhs);


}
#endif