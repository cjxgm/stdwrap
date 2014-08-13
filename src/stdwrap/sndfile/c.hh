#pragma once
#include <sndfile.h>




#include "../forward/begin.hh"
namespace sndfile
{
	namespace c
	{
#define FORWARD_FUNC(NAME, CNAME) \
		STDWRAP_FORWARD_FUNC(NAME, sf_ ## CNAME)

#define FORWARD_TYPE(NAME) \
		STDWRAP_FORWARD_TYPE(SF_ ## NAME)




		STDWRAP_FORWARD_TYPE(SNDFILE);

		namespace open
		{
			FORWARD_FUNC(file, open);
			FORWARD_FUNC(fd, open_fd);
			FORWARD_FUNC(vio, open_virtual);
			namespace info
			{
				FORWARD_TYPE(INFO);
				FORWARD_FUNC(check, format_check);
			};
			namespace mode
			{
				enum type
				{
					ro = SFM_READ,
					wo = SFM_WRITE,
					rw = SFM_RDWR,
				};
			};
		};

		FORWARD_FUNC(close, close);




#undef FORWARD_TYPE
#undef FORWARD_FUNC
	};
};
#include "../forward/end.hh"

