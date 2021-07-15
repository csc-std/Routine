#include "util.h"

#define slice(...) CSC::Slice<CSC::STR> (CSC::TYPEAS<struct anonymous>::id ,__VA_ARGS__)

namespace UNITTEST {
imports Auto get_int () {
	return VAR32 (2) ;
}

imports Auto get_float () {
	return SINGLE (3.1) ;
}

imports Auto get_string () {
	return slice ("test" ,"2") ;
}
} ;

#ifdef __CSC_TARGET_EXE__
exports int main () noexcept {
	using namespace UNITTEST ;
	const auto r1x = VAR32 (get_int ().cast (TYPEAS<VAR32>::id)) ;
	assert (r1x == VAR32 (2)) ;
	const auto r2x = SINGLE (get_float ().cast (TYPEAS<SINGLE>::id)) ;
	assert (r2x == SINGLE (3.1)) ;
	const auto r3x = Slice<STR> (get_string ().cast (TYPEAS<Slice<STR>>::id)) ;
	assert (r3x == slice ("test" ,"2")) ;
	return 0 ;
}
#endif

#include "csc2/csc_core.hpp.inl"