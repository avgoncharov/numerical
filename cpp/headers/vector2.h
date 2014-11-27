#ifndef _AVG_VECTOR2_
#define _AVG_VECTOR2_

#define __AVG_CPP11__
#include"common.h"

namespace avg_matrix
{
	// ����� (������ / �������) ������������ 2.
	class Vector2{
	public:
		Vector2();
		~Vector2();
		Vector2(const Vector2& source);
#ifdef __AVG_CPP11__
		Vector2(Vector2&& source);
#endif
		Vector2& operator=(const Vector2& source);

		// ���������� ������ �� ������� ������� (������ / �������).
		double& operator()(int i);
		
		// ���������� ����������� ������ �� ������� ������� (������ / �������).
		const double& operator()(int i)const;

	private:
		void createArrAndCopyFrom(const Vector2& source);
		double* _arr;
	};

	// �������� ������ (������ / ��������) �� �����.
	Vector2 operator*(double num, const Vector2& vec);

	// �������� ��������.
	Vector2 operator+(const Vector2& lhs, const Vector2& rhs);

	// ����� ������� � �����.
	std::ostream& operator<<(std::ostream& os, const Vector2& vec);
}


#endif