#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{
	/**
	* @classdesc Group of common math methods and constants.
	*/
	struct HK_UTILITY_EXPORT Math
	{
		/************************************************************************/
		/* Constant                                                             */
		/************************************************************************/

		/**
		* PI number.
		*/
		static const float PI;

		/**
		* The result of PI * 0.5f.
		*/
		static const float PIHALF;

		/**
		* The result of PI * 2.0f.
		*/
		static const float TWOPI;

		/**
		* Euler constant.
		*/
		static const float EULER;

		/**
		* Phi constant.
		*/
		static const float PHI;

		/**
		* Constant that converts degrees to radians (PI / 180).
		*/
		static const float DEG2RAD;

		/**
		* Constant that converts radians to degrees (180 / PI).
		*/
		static const float RAD2DEG;

		/************************************************************************/
		/* Basic Functions                                                      */
		/************************************************************************/

		/**
		* The product of all positive integers less than or equal to the given 
		* positive integer.
		*/
		static uint32
		Factorial(const uint32 Param) 
		{
			if (Param < 0) { return 0; }
			return ((Param == 1 || Param == 0) ? 1 : Factorial(Param - 1) * Param);
		}

		/**
		* Returns the absolute value of the given number.
		*/
		template <typename T>
		static T
		Abs(const T Param) 
		{
			return static_cast<T>(std::abs(Param));
		}

		/**
		* Returns e raised to the specific number.
		*/
		template<typename T>
		static T
		Exp(T Param) 
		{
			return static_cast<T>(std::exp(Param));
		}

		/**
		* Returns e raised to the specific number.
		*/
		template<>
		static float
	  Exp(float Param)
		{
			return std::expf(Param);
		}

		/**
		* Returns e raised to the specific number.
		*/
		template<>
		static long double
		Exp(long double Param)
		{
			return std::expl(Param);
		}

		/**
		* Returns e raised to the specific number.
		*/
		static float
		FastExp(float Param)
		{
			float result = 0.0f;
			for (uint32 ii = 0; ii < 45; ++ii)
			{
				result += std::powf(Param, static_cast<float>(ii)) 
								/ static_cast<float>(Factorial(ii));
			}
			return result;
		}

		/**
		* Returns the natural logarithm of the given number.
		*/
		template<typename T>
		static T
		Loge(const T Param) 
		{
			return static_cast<T>(std::log(Param));
		}

		/**
		* Returns the natural logarithm of the given number.
		*/
		template<>
		static float
		Loge(const float Param) 
		{
			return std::logf(Param);
		}

		/**
		* Returns the natural logarithm of the given number.
		*/
		template<>
		static long double
		Loge(const long double Param)
		{
			return std::logl(Param);
		}

		/**
		* Returns the logarithm of the given number.
		*/
		template<typename T>
		static T
		Log(const T Base, const T Param) 
		{
			return static_cast<T>(Loge(Param) / Loge(Base));
		}

		/**
		* Returns the sine of the given angle (radians).
		*/
		template<typename T>
		static T
		Sin(const T Angle) 
		{
			return static_cast<T>(std::sin(Angle));
		}

		/**
		* Returns the sine of the given angle (radians).
		*/
		template<>
		static float
		Sin(const float Angle) 
		{
			return std::sinf(Angle);
		}

		/**
		* Returns the sine of the given angle (radians).
		*/
		template<>
		static long double
		Sin(const long double Angle)
		{
			return std::sinl(Angle);
		}

		/**
		* Returns the arc-sine of the given angle (radians).
		*/
		template<typename T>
		static T
		Asin(const T Param) 
		{
			return static_cast<T>(std::asin(Param));
		}

		/**
		* Returns the arc-sine of the given angle (radians).
		*/
		template<>
		static float
		Asin(const float Param) 
		{
			return std::asinf(Param);
		}

		/**
		* Returns the arc-sine of the given angle (radians).
		*/
		template<>
		static long double
		Asin(const long double Param)
		{
			return std::asinl(Param);
		}

		/**
		* Returns the cosine of the given angle (radians).
		*/
		template<typename T>
		static T
		Cos(const T Param) 
		{
			return static_cast<T>(std::cos(Param));
		}

		/**
		* Returns the cosine of the given angle (radians).
		*/
		template<>
		static float
		Cos(const float Param) 
		{
			return std::cosf(Param);
		}

		/**
		* Returns the cosine of the given angle (radians).
		*/
		template<>
		static long double
		Cos(const long double Param)
		{
			return std::cosl(Param);
		}

		/**
		* Returns the arc-cosine of the given angle (radians).
		*/
		template<typename T>
		static T
		Acos(const T Param) 
		{
			return static_cast<T>(std::acos(Param));
		}

		/**
		* Returns the arc-cosine of the given angle (radians).
		*/
		template<>
		static float
		Acos(const float Param) 
		{
			return std::acosf(Param);
		}

		/**
		* Returns the arc-cosine of the given angle (radians).
		*/
		template<>
		static long double
		Acos(const long double Param)
		{
			return std::acosl(Param);
		}

		/**
		* Returns the tangent of the given angle (radians).
		*/
		template<typename T>
		static T
		Tan(const T Param) 
		{
			return static_cast<T>(std::tan(Param));
		}

		/**
		* Returns the tangent of the given angle (radians).
		*/
		template<>
		static float
		Tan(const float Param) 
		{
			return std::tanf(Param);
		}

		/**
		* Returns the tangent of the given angle (radians).
		*/
		template<>
		static long double
		Tan(const long double Param)
		{
			return std::tanl(Param);
		}

		/**
		* Returns the arc-tangent of the given angle (radians).
		*/
		template<typename T>
		static T
		Atan(const T Param) 
		{
			return static_cast<T>(std::atan(Param));
		}

		/**
		* Returns the arc-tangent of the given angle (radians).
		*/
		template<>
		static float
		Atan(const float Param) 
		{
			return std::atanf(Param);
		}

		/**
		* Returns the arc-tangent of the given angle (radians).
		*/
		template<>
		static long double
		Atan(const long double Param)
		{
			return std::atanl(Param);
		}

		/**
		* Returns the arc-tangent of the given angle (radians). Tan is y/x.
		*/
		template<typename T>
		static T
		Atan2(const T X, const T Y) 
		{
			return static_cast<T>(std::atan2(X, Y));
		}

		/**
		* Returns the arc-tangent of the given angle (radians). Tan is y/x.
		*/
		static float
		Atan2(const float X, const float Y) 
		{
			return std::atan2f(X, Y);
		}

		/**
		* Returns the arc-tangent of the given angle (radians). Tan is y/x.
		*/
		static long double
		Atan2(const long double X, const long double Y)
		{
			return std::atan2l(X, Y);
		}

		/**
		* Returns the cosine of the given angle (radians), using the tailor series.
		*/
		template<typename T>
		static T
		FastCos(const T Param) 
		{
			T result{};
			for (int n = 0; n < 45; ++n)
			{
				result += std::pow(-1, n) * (std::pow(Param, 2 * n) / Factorial(2 * n));
			}
			return result;
		}

		/**
		* Returns the sine of the given angle (radians), using the tailor series.
		*/
		template<typename T>
		static T
		FastSin(const T Param) 
		{
			T result{};
			for (int n = 0; n < 45; ++n)
			{
				result += std::pow(-1, n) * (std::pow(Param, (2 * n) + 1) / Factorial((2 * n) + 1));
			}
			return result;
		}

		/**
		* Returns the arc-tangent of the given angle (radians), using the tailor series.
		*/
		static float
		FastAtan(const float Param) 
		{
			if (Param < -1.0f || 1.0f < Param)
			{
				return 0.0f;
			}

			float result = 0.f;
			for (int n = 0; n < 45; ++n)
			{
				result += Pow(-1, n) * ((Pow(Param, static_cast<float>((2 * n) + 1) / (2 * n) + 1)));
			}

			return result;
		}

		/**
		* Returns square root of the given number.
		*/
		template<typename T>
		static T
		Sqrt(const T Param) 
		{
			return static_cast<T>(std::sqrt(Param));
		}

		/**
		* Returns square root of the given number.
		*/
		template<>
		static float
		Sqrt(const float Param) 
		{
			return std::sqrtf(Param);
		}

		/**
		* Returns square root of the given number.
		*/
		template<>
		static long double
		Sqrt(const long double Param)
		{
			return std::sqrtl(Param);
		}

		/**
		* Returns inverse square root of the given number.
		*/
		template<typename T>
		static T
		InvSqrt(const T Param) 
		{
			return static_cast<T>(1.0f / std::sqrt(Param));
		}

		/**
		* Returns inverse square root of the given number.
		*/
		template<>
		static float
		InvSqrt(const float Param)
		{
			return 1.0f / std::sqrtf(Param);
		}

		/**
		* Returns inverse square root of the given number.
		*/
		template<>
		static long double
		InvSqrt(const long double Param)
		{
			return (long double)1.0 / std::sqrtl(Param);
		}

		/**
		* Returns the "Base" raised to power "Exp".
		*/
		template<typename T>
		static T
		Pow(const T Base, const T Exp) 
		{
			return static_cast<T>(std::pow(Base, Exp));
		}

		/**
		* Returns the "Base" raised to power "Exp".
		*/
		template<>
		static float
		Pow(const float Base, const float Exp) 
		{
			return std::powf(Base, Exp);
		}

		/**
		* Returns the "Base" raised to power "Exp".
		*/
		template<>
		static long double
		Pow(const long double Base, const long double Exp)
		{
			return std::powl(Base, Exp);
		}

		/**
		* Returns the cube root of the given number.
		*/
		template<typename T>
		static T
		Cbrt(const T Param) 
		{
			return static_cast<T>(std::cbrt(Param));
		}

		/**
		* Returns the cube root of the given number.
		*/
		template<>
		static float
		Cbrt(const float Param) 
		{
			return std::cbrtf(Param);
		}

		/**
		* Returns the cube root of the given number.
		*/
		template<>
		static long double
		Cbrt(const long double Param)
		{
			return std::cbrtl(Param);
		}

		/**
		* Returns the value of the gamma function f the given number.
		*/
		template<typename T>
		static T
		Tgamma(const T Param) 
		{
			return static_cast<T>(std::tgamma(Param));
		}

		/**
		* Returns the value of the gamma function f the given number.
		*/
		template<>
		static float
		Tgamma(const float Param) 
		{
			return std::tgammaf(Param);
		}

		/**
		* Returns the value of the gamma function f the given number.
		*/
		template<>
		static long double
		Tgamma(const long double Param)
		{
			return std::tgammal(Param);
		}

		/**
		* Returns the given value rounded towards zero.
		*/
		template<typename T>
		static T
		Trunc(const T Param) 
		{
			return static_cast<T>(std::trunc(Param));
		}

		/**
		* Returns the given value rounded towards zero.
		*/
		template<>
		static float
		Trunc(const float Param) 
		{
			return std::truncf(Param);
		}

		/**
		* Returns the given value rounded towards zero.
		*/
		template<>
		static long double
		Trunc(const long double Param)
		{
			return std::truncl(Param);
		}

		/**
		* Returns the smallest integer value not less than the given value.
		*/
		template<typename T>
		static T
		Ceil(const T Param) 
		{
			return static_cast<T>(std::ceil(Param));
		}

		/**
		* Returns the smallest integer value not less than the given value.
		*/
		template<>
		static float
		Ceil(const float Param) 
		{
			return std::ceilf(Param);
		}

		/**
		* Returns the smallest integer value not less than the given value.
		*/
		template<>
		static long double
		Ceil(const long double Param)
		{
			return std::ceill(Param);
		}

		/**
		* Returns the largest integer value not greater than the given value.
		*/
		template<typename T>
		static T
		Floor(const T Param) 
		{
			return static_cast<T>(std::floor(Param));
		}

		/**
		* Returns the largest integer value not greater than the given value.
		*/
		template<>
		static float
		Floor(const float Param) 
		{
			return std::floorf(Param);
		}

		/**
		* Returns the largest integer value not greater than the given value.
		*/
		template<>
		static long double
		Floor(const long double Param)
		{
			return std::floorl(Param);
		}

		/**
		* Returns the nearest integer value to the given value, rounding halfway
		* cases away from zero.
		*/
		template<typename T>
		static T
		Round(const T Param) 
		{
			return static_cast<T>(std::round(Param));
		}

		/**
		* Returns the nearest integer value to the given value, rounding halfway
		* cases away from zero.
		*/
		template<>
		static float
		Round(const float Param) 
		{
			return std::roundf(Param);
		}

		/**
		* Returns the nearest integer value to the given value, rounding halfway
		* cases away from zero.
		*/
		template<>
		static long double
		Round(const long double Param)
		{
			return std::roundl(Param);
		}

		/**
		* Linearly interpolates between a and b by the step value.
		* 
		* @param A value.
		* @param B value.
		* @param Step value.
		*/
		template<typename T>
		static T
		Lerp(const T _a, const T _b, const T _step)
		{
			return _a + ((_b - _a) * _step);
		}

		/**
		* Clamps the given value between the given minimum value and maximum value.
		*/
		template< typename T>
		static T
		Clamp(const T _value, const T _min, const T _max)
		{
			if (_value < _min)
			{
				_value = _min;
			}
			else if (_value > _max)
			{
				_value = _max;
			}
			return _value;
		}
	};
}