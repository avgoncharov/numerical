#ifndef _AVG_VECTOR2_
#define _AVG_VECTOR2_
#include"matrix2x2.h"
#include<vector>
namespace avg_matrix
{
	class Vector2{
	public:
		Vector2();
		~Vector2();
		Vector2(const Vector2& source);
		Vector2& operator=(const Vector2& source);

		double& operator()(int i);
		const double& operator()(int i)const;

	private:
		void createArrAndCopyFrom(const Vector2& source);
		double* _arr;
	};

	Vector2 operator*(double num, const Vector2& vec);
	Vector2 operator*(const Vector2& vec, const Matrix2x2& matrix);
	Vector2 operator*(const Matrix2x2& matrix, const Vector2& vec);

	std::vector<Vector2> multiply(const Matrix2x2& matrix, const Vector2* begin, const Vector2* end);

}
#endif