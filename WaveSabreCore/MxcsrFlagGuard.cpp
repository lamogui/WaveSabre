#include "sys_buildfeatures.h"
#ifdef PROUT_WAVESABRE

#include <extern/WaveSabre/WaveSabreCore/MxcsrFlagGuard.h>

#include <xmmintrin.h>
#include <pmmintrin.h>

namespace WaveSabreCore
{
	MxcsrFlagGuard::MxcsrFlagGuard()
	{
		mxcsrRestore = _mm_getcsr();

		// Set SSE FTZ and DAZ flags
		_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
		_MM_SET_DENORMALS_ZERO_MODE(_MM_DENORMALS_ZERO_ON);
	}

	MxcsrFlagGuard::~MxcsrFlagGuard()
	{
		_mm_setcsr(mxcsrRestore);
	}
}

#endif // PROUT_WAVESABRE