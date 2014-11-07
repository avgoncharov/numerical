#ifndef _AVG_MATRIX_
#define _AVG_MATRIX_
namespace avg_matrix
{
	class MatrixOperations
	{
	public:
		static double** transpose(double* matrix[], int row_count, int column_count);
		static double** multiple(double* lhs[], double* rhs[], int i, int k, int j);
	};
}
#endif