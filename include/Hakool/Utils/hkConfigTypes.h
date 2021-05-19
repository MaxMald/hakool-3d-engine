#pragma once

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdarg>
#include <cmath>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

#include <memory>

#include <vector>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <bitset>
#include <array>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <limits>

#include <stdint.h>
#include <chrono>


#include <Hakool\Utils\hkConfigPlatform.h>

#if HK_PLATFORM == HK_PLATFORM_PS4
#include <scebase.h>
#endif

#define hcMap       std::map
#define hcPair      std::pair
#define hcMakePair  std::make_pair
#define hcTo_String std::to_string
#define hcChrono    std::chrono;
#define hc_str_to_int std::stoi;

#define HK_GETLINE __LINE__
#define HK_GETFILE __FILE__
#define HK_BREAKLINE '\n'
#define HK_ZeroMem SecureZeroMemory 
#define HK_MAX_FLOAT 3.402823466e+38F

namespace DEF_INIT
{
	enum E {
		kZero = 0,
		kOne
	};
}

namespace hk
{
	typedef unsigned char uchar;
	typedef uint8_t uint8;
	typedef uint16_t uint16;
	typedef uint32_t uint32;
	typedef uint64_t uint64;
	typedef int8_t int8;
	typedef int16_t int16;
	typedef int32_t int32;
	typedef int64_t int64;
	typedef size_t hkSize;

	MS_ALIGN(16) class QWord
	{
	public:

		QWord() : m_lower(0), m_upper(0) {}
		explicit QWord(bool from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
		explicit QWord(uint8 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
		explicit QWord(int8 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
		explicit QWord(uint16 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
		explicit QWord(int16 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
		explicit QWord(uint32 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
		explicit QWord(int32 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
		explicit QWord(uint64 from) : m_lower(from), m_upper(0) {}
		explicit QWord(int64 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
		explicit QWord(float from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
		explicit QWord(double from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}

		operator int64() const { return static_cast<uint64>(m_lower); }

	public:

		uint64  m_lower;
		
		int64   m_upper;

	}GCC_ALIGN(16);

	typedef QWord int128;
	typedef QWord uint128;

	typedef char ANSICHAR;
	typedef wchar_t UNICODECHAR;

	typedef std::basic_string<ANSICHAR, std::char_traits<ANSICHAR>, std::allocator<ANSICHAR>> String;
	typedef std::basic_string<UNICODECHAR, std::char_traits<UNICODECHAR>, std::allocator<UNICODECHAR>> WString;
	typedef std::unique_ptr<std::istream> InStreamPtr;
	typedef std::unique_ptr<std::ostream> OutStreamPtr;
	typedef std::istream InStream;
	typedef std::ostream OutStream;
	typedef std::ofstream OutFileStream;
	typedef std::stringstream StringStream;

	template <typename T, typename A = std::allocator < T > >
	using Vector = std::vector<T,A>;

	template<class K, class T, class P = std::less<K>, class _Alloc = std::allocator<std::pair<const K, T>>>
	using Map = std::map<K, T, P, _Alloc>;

	template<class K, class T, class H = std::hash<K>, class _KeyEqual = std::equal_to<K>, class _Alloc = std::allocator<std::pair<K, T>>>
	using UnorderedMap = std::unordered_map<K, T, H, _KeyEqual, _Alloc>;

	template<class T, class A = std::deque<T>>
	using Queue = std::queue<T, A>;

	template<class T, class A = std::deque<T>>
	using Stack = std::stack<T, A>;

	template<class C>
	using TimePoint = std::chrono::time_point<C>;

	using SystemClock= std::chrono::system_clock;

	using Milliseconds = std::chrono::milliseconds;
};