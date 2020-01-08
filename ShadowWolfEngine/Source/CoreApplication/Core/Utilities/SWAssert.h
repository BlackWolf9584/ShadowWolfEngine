#pragma once 

#ifdef SW_DEBUG
	#define SW_ENABLE_ASSERTS
#endif

#ifdef SW_ENABLE_ASSERTS
	#define SW_ASSERT_NO_MESSAGE(condition) {if(!(condition)) { SW_ERROR("Assertion Failed"); __debugbreak(); } }
	#define SW_ASSERT_MESSAGE(condition, ...) {if(!(condition)) { SW_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

	#define SW_ASSERT_RESOLVE(arg1, arg2, macro, ...) macro
	#define SW_GET_ASSERT_MACRO(...) SW_EXPAND_VARGS(SW_ASSERT_RESOLVE(__VA_ARGS__, SW_ASSERT_MESSAGE, SW_ASSERT_NO_MESSAGE))

	#define SW_ASSERT(...) SW_EXPAND_VARGS(SW_GET_ASSERT_MACRO(__VA_ARGS__)(__VA_ARGS__) )
	#define SW_CORE_ASSERT(...) SW_EXPAND_VARGS(SW_GET_ASSERT_MACRO(__VA_ARGS__)(__VA_ARGS__) )
#else
	#define SW_ASSERT(...)
	#define SW_CORE_ASSERT(...)
#endif