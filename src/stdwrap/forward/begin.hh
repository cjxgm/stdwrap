// no #pragma once deliberately

#ifdef STDWRAP_FORWARD_BEGIN
#error	you should #include "forward/end.hh" after your previous \
		inclusion of this file!
#else
#define STDWRAP_FORWARD_BEGIN




#define STDWRAP_RETURN(EXPR) -> decltype(EXPR) { return EXPR; }

#define STDWRAP_FORWARD_FUNC(NAME, CNAME) \
		template <class ...Args> \
		inline auto NAME (Args&& ...args) \
			STDWRAP_RETURN(CNAME (std::forward<Args>(args)...));

#define STDWRAP_FORWARD_TYPE(CNAME) \
		using type = ::CNAME




#endif

