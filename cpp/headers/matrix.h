#ifndef _AVG_MATRIX_
#define _AVG_MATRIX_
namespace avg_matrix
{
	//Транспонирует матрицу размерностью row_count x column_count
	double** transpose(const double* const* matrix, int row_count, int column_count);

	//Умножение матриц.
	double** multiple(const double* const* lhs, const double* const* rhs, int i, int k, int j);
	//-------------------------------------------------
	//Опредилитель матрицы 2x2.
	double det2x2(const double* const* m);

	//Минор матрицы 2x2.
	double** minor2x2(const double* const* m);

	//Транспонирование матрицы 2x2.
	double** transpnse2x2(const double* const* m);

	//Нахождение обратной матрицы 2x2.
	double** inverse2x2(const double* const* m);

	//Умнажает матрицу 2x2 на вектор 2.
	double* multipleM2x2ToV2(const double* const* m, const double* v);

	//Умножает матрицу 2x2 на каждый вектор 2, из множества заданного первым вектором и указателем на место сразу за последним.
	double** multipleM2x2ToArrOfV2(const double* const* m, const double* const* begin, const double* const* end);
	//-------------------------------------------------------
	//Создает матрицу NxM.
	double** createNxM(int n, int m);

	//Создает квадратную матрицу NxN.
	double** createNxN(int n);

	//Удаляет матрицу NxM. Достаточно указать только количество строк.
	void deleteNxM(double* m[], int row_num);
}
#endif