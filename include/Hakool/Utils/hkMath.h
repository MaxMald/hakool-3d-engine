#pragma once

#include <Hakool\Utils\hkUtilsPrerequisites.h>

namespace hk
{
	/**
	* Common math operations and constants.
	*/
	struct HK_UTILITY_EXPORT Math
	{

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

		/**
		* Calculates product of all positive integers less than or equal to the 
		* given positive integer.
		* 
		* @param _value Number.
		* 
		* @returns Returns the product of all positive integers less than or equal 
		* to the given positive integer.
		*/
		static uint32
		Factorial(const uint32 _value) 
		{
			if (_value < 0) { return 0; }
			return ((_value == 1 || _value == 0) ? 1 : Factorial(_value - 1) * _value);
		}

		/**
		* Calculate the absolute value of the given number.
		* 
		* @param T _value Number.
		* 
		*	@returns The absolute value of the given number.
		*/
		template <typename T>
		static T
		Abs(const T _value) 
		{
			return static_cast<T>(std::abs(_value));
		}

		/**
		* Returns e raised to the specific number.
		* 
		* @param _value Number.
		* 
		* @returns Returns e raised to the specific number.
		*/
		template<typename T>
		static T
		_exp(T _value) 
		{
			return static_cast<T>(std::exp(_value));
		}

		/**
		* Returns e raised to the specific number.
		*
		* @param _value Number.
		*
		* @returns Returns e raised to the specific number.
		*/
		template<>
		static float
	  _exp(float _value)
		{
			return std::expf(_value);
		}

		/**
		* Returns e raised to the specific number.
		*
		* @param _value Number.
		*
		* @returns Returns e raised to the specific number.
		*/
		template<>
		static long double
		_exp(long double _value)
		{
			return std::expl(_value);
		}

		/**
		* Returns e raised to the specific number.
		*
		* @param _value Number.
		*
		* @returns Returns e raised to the specific number.
		*/
		static float
		FastExp(float _value)
		{
			float result = 0.0f;
			for (uint32 ii = 0; ii < 45; ++ii)
			{
				result += std::powf(_value, static_cast<float>(ii)) 
								/ static_cast<float>(Factorial(ii));
			}
			return result;
		}

		/**
		* Returns the natural logarithm of the given number.
		* 
		* @param _value Number.
		*
		* @returns Returns the natural logarithm of the given number.
		*/
		template<typename T>
		static T
		Loge(const T _value) 
		{
			return static_cast<T>(std::log(_value));
		}

		/**
		* Returns the natural logarithm of the given number.
		*
		* @param _value Number.
		*
		* @returns Returns the natural logarithm of the given number.
		*/
		template<>
		static float
		Loge(const float _value) 
		{
			return std::logf(_value);
		}

		/**
		* Returns the natural logarithm of the given number.
		*
		* @param _value Number.
		*
		* @returns Returns the natural logarithm of the given number.
		*/
		template<>
		static long double
		Loge(const long double _value)
		{
			return std::logl(_value);
		}

		/**
		* Returns the logarithm of the given number.
		* 
		* @param _base Base.
		* @param _value Number.
		* 
		* @returns Returns the logarithm of the given number.
		*/
		template<typename T>
		static T
		Log(const T _base, const T _value) 
		{
			return static_cast<T>(Loge(_value) / Loge(_base));
		}

		/**
		* Returns the sine of the given angle (radians).
		* 
		* @param _angle Angle in radians.
		* 
		* @returns Returns the sine of the given angle (radians).
		*/
		template<typename T>
		static T
		Sin(const T _angle) 
		{
			return static_cast<T>(std::sin(_angle));
		}

		/**
		* Returns the sine of the given angle (radians).
		*
		* @param _angle Angle in radians.
		*
		* @returns Returns the sine of the given angle (radians).
		*/
		template<>
		static float
		Sin(const float _angle) 
		{
			return std::sinf(_angle);
		}

		/**
		* Returns the sine of the given angle (radians).
		*
		* @param _angle Angle in radians.
		*
		* @returns Returns the sine of the given angle (radians).
		*/
		template<>
		static long double
		Sin(const long double _angle)
		{
			return std::sinl(_angle);
		}

		/**
		* Returns the arc-sine of the given angle (radians).
		* 
		* @param _angle Angle in radians.
		*
		* @returns Returns the arc-sine of the given angle (radians).
		*/
		template<typename T>
		static T
		Asin(const T _angle)
		{
			return static_cast<T>(std::asin(_angle));
		}

		/**
		* Returns the arc-sine of the given angle (radians).
		*
		* @param _angle Angle in radians.
		*
		* @returns Returns the arc-sine of the given angle (radians).
		*/
		template<>
		static float
		Asin(const float _angle)
		{
			return std::asinf(_angle);
		}

		/**
		* Returns the arc-sine of the given angle (radians).
		*
		* @param _angle Angle in radians.
		*
		* @returns Returns the arc-sine of the given angle (radians).
		*/
		template<>
		static long double
		Asin(const long double _angle)
		{
			return std::asinl(_angle);
		}

		/**
		* Returns the cosine of the given angle (radians).
		* 
		* @param _angle Angle in radians.
		*
		* @returns Returns the cosine of the given angle (radians).
		*/
		template<typename T>
		static T
		Cos(const T _angle) 
		{
			return static_cast<T>(std::cos(_angle));
		}

		/**
		* Returns the cosine of the given angle (radians).
		*
		* @param _angle Angle in radians.
		*
		* @returns Returns the cosine of the given angle (radians).
		*/
		template<>
		static float
		Cos(const float _angle) 
		{
			return std::cosf(_angle);
		}

		/**
		* Returns the cosine of the given angle (radians).
		*
		* @param _angle Angle in radians.
		*
		* @returns Returns the cosine of the given angle (radians).
		*/
		template<>
		static long double
		Cos(const long double _angle)
		{
			return std::cosl(_angle);
		}

		/**
		* Returns the arc-cosine of the given angle (radians).
		* 
		* @param _angle Angle in radians.
		*
		* @returns Returns the arc-cosine of the given angle (radians).
		*/
		template<typename T>
		static T
		Acos(const T _angle)
		{
			return static_cast<T>(std::acos(_angle));
		}

		/**
		* Returns the arc-cosine of the given angle (radians).
		*
		* @param _angle Angle in radians.
		*
		* @returns Returns the arc-cosine of the given angle (radians).
		*/
		template<>
		static float
		Acos(const float _angle)
		{
			return std::acosf(_angle);
		}

		/**
		* Returns the arc-cosine of the given angle (radians).
		*
		* @param _angle Angle in radians.
		*
		* @returns Returns the arc-cosine of the given angle (radians).
		*/
		template<>
		static long double
		Acos(const long double _angle)
		{
			return std::acosl(_angle);
		}

		/**
		* Returns the tangent of the given angle (radians).
		*
		* @param _angle Angle in radians.
		*
		* @returns Returns the tangent of the given angle (radians).
		*/
		template<typename T>
		static T
		Tan(const T _angle)
		{
			return static_cast<T>(std::tan(_angle));
		}

		/**
		* Returns the tangent of the given angle (radians).
		*
		* @param _angle Angle in radians.
		*
		* @returns Returns the tangent of the given angle (radians).
		*/
		template<>
		static float
		Tan(const float _angle)
		{
			return std::tanf(_angle);
		}

		/**
		* Returns the tangent of the given angle (radians).
		*
		* @param _angle Angle in radians.
		*
		* @returns Returns the tangent of the given angle (radians).
		*/
		template<>
		static long double
		Tan(const long double _angle)
		{
			return std::tanl(_angle);
		}

		/**
		* Returns the arc-tangent of the given angle (radians).
		* 
		* @param _angle Angle in radians.
		*
		* @returns Returns the arc-tangent of the given angle (radians).
		*/
		template<typename T>
		static T
		Atan(const T _angle)
		{
			return static_cast<T>(std::atan(_angle));
		}

		/**
		* Returns the arc-tangent of the given angle (radians).
		*
		* @param _angle Angle in radians.
		*
		* @returns Returns the arc-tangent of the given angle (radians).
		*/
		template<>
		static float
		Atan(const float _angle)
		{
			return std::atanf(_angle);
		}

		/**
		* Returns the arc-tangent of the given angle (radians).
		*
		* @param _angle Angle in radians.
		*
		* @returns Returns the arc-tangent of the given angle (radians).		
		*/
		template<>
		static long double
		Atan(const long double _angle)
		{
			return std::atanl(_angle);
		}

		/**
		* Returns the arc-tangent of the given angle (radians). Tan is y/x.
		* 
		* @param _x X value.
		* @param _y Y value.
		*
		* @returns Returns the arc-tangent of the given angle (radians).
		*/
		template<typename T>
		static T
		Atan2(const T _x, const T _y) 
		{
			return static_cast<T>(std::atan2(_x, _y));
		}

		/**
		* Returns the arc-tangent of the given angle (radians). Tan is y/x.
		*
		* @param _x X value.
		* @param _y Y value.
		*
		* @returns Returns the arc-tangent of the given angle (radians).
		*/
		static float
		Atan2(const float _x, const float _y) 
		{
			return std::atan2f(_x, _y);
		}

		/**
		* Returns the arc-tangent of the given angle (radians). Tan is y/x.
		*
		* @param _x X value.
		* @param _y Y value.
		*
		* @returns Returns the arc-tangent of the given angle (radians).
		*/
		static long double
		Atan2(const long double _x, const long double _y)
		{
			return std::atan2l(_x, _y);
		}

		/**
		* Returns the cosine of the given angle (radians). This operation uses the 
		* tailor series.
		* 
		* @param _angle Angle in radians.
		* 
		* @returns Returns the cosine of the given angle (radians).
		*/
		template<typename T>
		static T
		FastCos(const T _angle)
		{
			T result{};
			for (int n = 0; n < 45; ++n)
			{
				result += std::pow(-1, n) * (std::pow(_angle, 2 * n) / Factorial(2 * n));
			}
			return result;
		}

		/**
		* Returns the sine of the given angle (radians). This operation uses the
		* tailor series.
		*
		* @param _angle Angle in radians.
		*
		* @returns Returns the sine of the given angle (radians).
		*/
		template<typename T>
		static T
		FastSin(const T _angle)
		{
			T result{};
			for (int n = 0; n < 45; ++n)
			{
				result += std::pow(-1, n) * (std::pow(_angle, (2 * n) + 1) / Factorial((2 * n) + 1));
			}
			return result;
		}

		/**
		* Returns the arc-tangent of the given angle (radians). This operation uses 
		* the tailor series.
		*
		* @param _angle Angle in radians.
		*
		* @returns Returns the cosine of the given angle (radians).
		*/
		static float
		FastAtan(const float _angle) 
		{
			if (_angle < -1.0f || 1.0f < _angle)
			{
				return 0.0f;
			}

			float result = 0.f;
			for (int n = 0; n < 45; ++n)
			{
				result += Pow(-1, n) * ((Pow(_angle, static_cast<float>((2 * n) + 1) / (2 * n) + 1)));
			}

			return result;
		}

		/**
		* Returns square root of the given number.
		* 
		* @param _value Number.
		* 
		* @return Returns square root of the given number.
		*/
		template<typename T>
		static T
		Sqrt(const T _value) 
		{
			return static_cast<T>(std::sqrt(_value));
		}

		/**
		* Returns square root of the given number.
		*
		* @param _value Number.
		*
		* @return Returns square root of the given number.
		*/
		template<>
		static float
		Sqrt(const float _value) 
		{
			return std::sqrtf(_value);
		}

		/**
		* Returns square root of the given number.
		*
		* @param _value Number.
		*
		* @return Returns square root of the given number.
		*/
		template<>
		static long double
		Sqrt(const long double _value)
		{
			return std::sqrtl(_value);
		}

		/**
		* Returns inverse square root of the given number.
		* 
		* @param _value Number.
		*
		* @return Returns inverse square root of the given number.
		*/
		template<typename T>
		static T
		InvSqrt(const T _value) 
		{
			return static_cast<T>(1.0f / std::sqrt(_value));
		}

		/**
		* Returns inverse square root of the given number.
		*
		* @param _value Number.
		*
		* @return Returns inverse square root of the given number.
		*/
		template<>
		static float
		InvSqrt(const float _value)
		{
			return 1.0f / std::sqrtf(_value);
		}

		/**
		* Returns inverse square root of the given number.
		*
		* @param _value Number.
		*
		* @return Returns inverse square root of the given number.
		*/
		template<>
		static long double
		InvSqrt(const long double _value)
		{
			return (long double)1.0 / std::sqrtl(_value);
		}

		/**
		* Returns the "_base" raised to power "_exp".
		* 
		* @param _base Base number.
		* @param _exp Exponent number.
		* 
		* @return Returns the "_base" raised to power "_exp".
		*/
		template<typename T>
		static T
		Pow(const T _base, const T _exp) 
		{
			return static_cast<T>(std::pow(_base, _exp));
		}

		/**
		* Returns the "_base" raised to power "_exp".
		*
		* @param _base Base number.
		* @param _exp Exponent number.
		*
		* @return Returns the "_base" raised to power "_exp".
		*/
		template<>
		static float
		Pow(const float _base, const float _exp) 
		{
			return std::powf(_base, _exp);
		}

		/**
		* Returns the "_base" raised to power "_exp".
		*
		* @param _base Base number.
		* @param _exp Exponent number.
		*
		* @return Returns the "_base" raised to power "_exp".
		*/
		template<>
		static long double
		Pow(const long double _base, const long double _exp)
		{
			return std::powl(_base, _exp);
		}

		/**
		* Returns the cube root of the given number.
		* 
		* @param _value Number.
		* 
		* @return Returns the cube root of the given number.
		*/
		template<typename T>
		static T
		Cbrt(const T _value) 
		{
			return static_cast<T>(std::cbrt(_value));
		}

		/**
		* Returns the cube root of the given number.
		*
		* @param _value Number.
		*
		* @return Returns the cube root of the given number.
		*/
		template<>
		static float
		Cbrt(const float _value) 
		{
			return std::cbrtf(_value);
		}

		/**
		* Returns the cube root of the given number.
		*
		* @param _value Number.
		*
		* @return Returns the cube root of the given number.
		*/
		template<>
		static long double
		Cbrt(const long double _value)
		{
			return std::cbrtl(_value);
		}

		/**
		* Returns the value of the gamma function of the given number.
		* 
		* @param _value Number.
		*
		* @return Returns the value of the gamma function of the given number.
		*/
		template<typename T>
		static T
		Tgamma(const T _value) 
		{
			return static_cast<T>(std::tgamma(_value));
		}

		/**
		* Returns the value of the gamma function of the given number.
		*
		* @param _value Number.
		*
		* @return Returns the value of the gamma function of the given number.
		*/
		template<>
		static float
		Tgamma(const float _value) 
		{
			return std::tgammaf(_value);
		}

		/**
		* Returns the value of the gamma function of the given number.
		*
		* @param _value Number.
		*
		* @return Returns the value of the gamma function of the given number.
		*/
		template<>
		static long double
		Tgamma(const long double _value)
		{
			return std::tgammal(_value);
		}

		/**
		* Returns the given value rounded towards zero.
		* 
		* @param _value Number.
		* 
		* @return Returns the given value rounded towards zero.
		*/
		template<typename T>
		static T
		Trunc(const T _value) 
		{
			return static_cast<T>(std::trunc(_value));
		}

		/**
		* Returns the given value rounded towards zero.
		*
		* @param _value Number.
		*
		* @return Returns the given value rounded towards zero.
		*/
		template<>
		static float
		Trunc(const float _value) 
		{
			return std::truncf(_value);
		}

		/**
		* Returns the given value rounded towards zero.
		*
		* @param _value Number.
		*
		* @return Returns the given value rounded towards zero.
		*/
		template<>
		static long double
		Trunc(const long double _value)
		{
			return std::truncl(_value);
		}

		/**
		* Returns the smallest integer value not less than the given value.
		* 
		* @param _value Number.
		* 
		* @return Returns the smallest integer value not less than the given value.
		*/
		template<typename T>
		static T
		Ceil(const T _value) 
		{
			return static_cast<T>(std::ceil(_value));
		}

		/**
		* Returns the smallest integer value not less than the given value.
		*
		* @param _value Number.
		*
		* @return Returns the smallest integer value not less than the given value.
		*/
		template<>
		static float
		Ceil(const float _value) 
		{
			return std::ceilf(_value);
		}

		/**
		* Returns the smallest integer value not less than the given value.
		*
		* @param _value Number.
		*
		* @return Returns the smallest integer value not less than the given value.
		*/
		template<>
		static long double
		Ceil(const long double _value)
		{
			return std::ceill(_value);
		}

		/**
		* Returns the largest integer value not greater than the given value.
		* 
		* @param _value Number.
		* 
		* @return Returns the largest integer value not greater than the given 
		* value.
		*/
		template<typename T>
		static T
		Floor(const T _value) 
		{
			return static_cast<T>(std::floor(_value));
		}

		/**
		* Returns the largest integer value not greater than the given value.
		*
		* @param _value Number.
		*
		* @return Returns the largest integer value not greater than the given
		* value.
		*/
		template<>
		static float
		Floor(const float _value) 
		{
			return std::floorf(_value);
		}

		/**
		* Returns the largest integer value not greater than the given value.
		*
		* @param _value Number.
		*
		* @return Returns the largest integer value not greater than the given
		* value.
		*/
		template<>
		static long double
		Floor(const long double _value)
		{
			return std::floorl(_value);
		}

		/**
		* Returns the nearest integer value to the given value, rounding halfway
		* cases away from zero.
		* 
		* @param _value Number.
		* 
		* @return Returns the nearest integer value to the given value, rounding 
		* halfway cases away from zero.
		*/
		template<typename T>
		static T
		Round(const T _value) 
		{
			return static_cast<T>(std::round(_value));
		}

		/**
		* Returns the nearest integer value to the given value, rounding halfway
		* cases away from zero.
		*
		* @param _value Number.
		*
		* @return Returns the nearest integer value to the given value, rounding
		* halfway cases away from zero.
		*/
		template<>
		static float
		Round(const float _value) 
		{
			return std::roundf(_value);
		}

		/**
		* Returns the nearest integer value to the given value, rounding halfway
		* cases away from zero.
		*
		* @param _value Number.
		*
		* @return Returns the nearest integer value to the given value, rounding
		* halfway cases away from zero.
		*/
		template<>
		static long double
		Round(const long double _value)
		{
			return std::roundl(_value);
		}

		/**
		* Linearly interpolates between value "a" and value "b" at the "step" value.
		* 
		* @param _a value.
		* @param _b value.
		* @param _step Step value.
		* 
		* @returns The interpolated value at the "step" value
		*/
		template<typename T>
		static T
		Lerp(const T _a, const T _b, const T _step)
		{
			return _a + ((_b - _a) * _step);
		}

		/**
		* Linearly interpolate between two points at the "step" point.
		* 
		* @param _aX The x component of the Point A.
		* @param _aY The y component of the Point A.
		* @param _bX The x component of the Point B.
		* @param _bY the y component of the Point B.
		* @param _stepX The x component of the Step Point.
		* @param _stepY The y component of the Step Point.
		* 
		* @returns The bi-linear interpolation between two points at a given 
		* "step" point.
		*/
		template<typename T>
		static T
		BiLerp
		(
			const T _aX, 
			const T _aY, 
			const T _bX, 
			const T _bY, 
			const T _stepX, 
			const T _stepY
		)
		{
			T l1 = _aX + ((_bX - _aX) * _stepX);
			T l2 = _aY + ((_bY - _aY) * _stepX);
			return l1 + ((l2 - l1) * _stepY);
		}

		/**
		* Clamps the given value between the given minimum value and maximum value.
		* 
		* @param _value Number to be clamped.
		* @param _min Minimum value.
		* @param _max Maximum value.
		* 
		* @returns Clamped value between minimum and maximum value.
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