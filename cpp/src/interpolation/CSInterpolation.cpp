#include "..\..\headers\interpolation\CSInterpolation.h"
#include <cmath>
avg_interpolation::CSInterpolation::CSInterpolation(const double* xArr, const double* fArr, int length)
{
	_len = length;
	_coaffs = new CSIStruct[length];

	FindCoaffs(xArr, fArr);
}

avg_interpolation::CSInterpolation::~CSInterpolation()
{
	if (_coaffs)
		delete[] _coaffs;
}

double avg_interpolation::CSInterpolation::GetFuncValueFor(double x)
{
	CSIResultPair result = GetFuncValueAndDerivativeFor(x);
	return result.F;
}

avg_interpolation::CSIResultPair avg_interpolation::CSInterpolation::GetFuncValueAndDerivativeFor(double x)
{
	CSIStruct s = _coaffs[0];

	if (x < _coaffs[0].x) {
		s = _coaffs[0];
	}
	else {
		if (x > _coaffs[_len - 1].x)
			s = _coaffs[_len - 1];
		else {
			int index = FindIndexOf(x);
			s = _coaffs[index];
		}
	}

	double dx = x - s.x;
	double fv = s.a + (s.b + (s.c / 2.0 + s.d * dx / 6.0) * dx) * dx;
	double dfv = s.b + (s.c + s.d * dx / 2.0) * dx;

	CSIResultPair result;
	result.F = fv;
	result.dF = dfv;

	return result;
}

void avg_interpolation::CSInterpolation::FindCoaffs(const double* xArr, const double* fArr)
{
	for (int i = 0; i < _len; ++i) {
		_coaffs[i].x = xArr[i];
		_coaffs[i].a = fArr[i];
		_coaffs[i].b = 0;
		_coaffs[i].c = 0;
		_coaffs[i].d = 0;
	}

	double* alpha = new double[_len];
	double* betta = new double[_len];

	for (int i = 0; i < _len; ++i) {
		alpha[i] = 0;
		betta[i] = 0;
	}

	double hi, hi1;
	double A, C, B, F, z;

	for (int i = 1; i < _len - 1; ++i) {
		hi = _coaffs[i].x - _coaffs[i - 1].x;
		hi1 = _coaffs[i + 1].x - _coaffs[i].x;

		A = hi;
		C = 2.0 * (hi + hi1);
		B = hi1;
		F = 6.0 * ((fArr[i + 1] - fArr[i]) / hi1 - (fArr[i] - fArr[i - 1]) / hi);
		z = (A * alpha[i - 1] + C);

		alpha[i] = -B / z;
		betta[i] = (F - A * betta[i - 1]) / z;
	}

	for (int i = _len - 2; i > 0; --i) {
		_coaffs[i].c = alpha[i] * _coaffs[i + 1].c + betta[i];
	}

	for (int i = _len - 1; i > 0; --i) {
		hi = _coaffs[i].x - _coaffs[i - 1].x;
		_coaffs[i].d = (_coaffs[i].c - _coaffs[i - 1].c) / hi;
		_coaffs[i].b = hi * (2.0 * _coaffs[i].c + _coaffs[i - 1].c) / 6.0 + (_coaffs[i].a - _coaffs[i - 1].a) / hi;
	}
	
	delete[] betta;
	delete[] alpha;

}

int avg_interpolation::CSInterpolation::FindIndexOf(double x)
{
	int start = 0;
	int end = _len - 1;
	int curr = (end + start) / 2;

	while (start + 1 < end) {
		if (_coaffs[curr].x == x)
			return curr;

		if (x < _coaffs[curr].x)
			end = curr;
		else
			start = curr;

		curr = (end + start) / 2;
	}

	return end;
}