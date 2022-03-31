#pragma once
#include <iostream>
namespace ft
{
	template<class T, T v>
	struct integral_constant {
		static const T value = 	v;
		typedef T 					value_type;
		typedef integral_constant 	type;
	};

	template <typename T>
	struct is_integral : integral_constant<bool, false> {};

	template<>
	struct is_integral<bool> : integral_constant<bool, true> {};

	template<>
	struct is_integral<char> : integral_constant<bool, true> {};

	template<>
	struct is_integral<char16_t> : integral_constant<bool, true> {};

	template<>
	struct is_integral<char32_t> : integral_constant<bool, true> {};

	template<>
	struct is_integral<wchar_t> : integral_constant<bool, true> {};

	template<>
	struct is_integral<short> : integral_constant<bool, true> {};

	template<>
	struct is_integral<int> : integral_constant<bool, true> {};

	template<>
	struct is_integral<long> : integral_constant<bool, true> {};

	template<>
	struct is_integral<long long> : integral_constant<bool, true> {};

	template <bool, typename T = void>
	struct enable_if
	{};

	template <typename T>
	struct enable_if<true, T> {
	typedef T type;
	};
}
