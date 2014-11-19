#ifndef _AVG_MATRIX_
#define _AVG_MATRIX_
namespace avg_matrix
{
	//������������� ������� ������������ row_count x column_count
	double** transpose(const double* const* matrix, int row_count, int column_count);

	//��������� ������.
	double** multiple(const double* const* lhs, const double* const* rhs, int i, int k, int j);
	//-------------------------------------------------
	//������������ ������� 2x2.
	double det2x2(const double* const* m);

	//����� ������� 2x2.
	double** minor2x2(const double* const* m);

	//���������������� ������� 2x2.
	double** transpnse2x2(const double* const* m);

	//���������� �������� ������� 2x2.
	double** inverse2x2(const double* const* m);

	//�������� ������� 2x2 �� ������ 2.
	double* multipleM2x2ToV2(const double* const* m, const double* v);

	//�������� ������� 2x2 �� ������ ������ 2, �� ��������� ��������� ������ �������� � ���������� �� ����� ����� �� ���������.
	double** multipleM2x2ToArrOfV2(const double* const* m, const double* const* begin, const double* const* end);
	//-------------------------------------------------------
	//������� ������� NxM.
	double** createNxM(int n, int m);

	//������� ���������� ������� NxN.
	double** createNxN(int n);

	//������� ������� NxM. ���������� ������� ������ ���������� �����.
	void deleteNxM(double* m[], int row_num);
}
#endif