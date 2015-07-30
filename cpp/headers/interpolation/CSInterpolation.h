#ifndef __CS_INTERPOLATION__
#define __CS_INTERPOLATION__
namespace avg_interpolation
{
	struct CSIResultPair
	{		
		double F;
		double dF;
	};

	class CSInterpolation final {
	public:
		CSInterpolation(const double* xArr, const double* fArr, int length);
		double GetFuncValueFor(double x);
		CSIResultPair GetFuncValueAndDerivativeFor(double x);
		~CSInterpolation();

	private:
		struct CSIStruct
		{
			double x;
			double a;
			double b;
			double c;
			double d;
		};

		class AlphaBetta{
			
		};

		void FindCoaffs(const double* xArr, const double* fArr);
		int FindIndexOf(double x);
		
		CSIStruct* _coaffs;
		int _len;
	};
}
#endif