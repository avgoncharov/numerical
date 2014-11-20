#ifndef _AVG_MATRIX2X2_
#define _AVG_MATRIX2X2_

namespace avg_matrix
{	
	//Умножает матрицу 2x2 на каждый вектор 2, из множества заданного первым вектором и указателем на место сразу за последним.
	double** multipleM2x2ToArrOfV2(const double* const* m, const double* const* begin, const double* const* end);

	class Matrix2x2{
	public:
		Matrix2x2();
		Matrix2x2(const Matrix2x2& source);
		Matrix2x2& operator=(const Matrix2x2& source);
		~Matrix2x2();

		Matrix2x2 inverse();
		Matrix2x2 transponse();
		Matrix2x2 minor();
		double det();
		double& operator()(int i, int j);
		const double& operator()(int i, int j) const;
	private:
		void Copy(const Matrix2x2& source);
		void createArr();
		void deleteArr();

		double** _arr;
	};

	Matrix2x2 operator*(double num, const Matrix2x2& matrix);
	Matrix2x2 operator*(const Matrix2x2& lhs, const Matrix2x2& rhs);


}
#endif