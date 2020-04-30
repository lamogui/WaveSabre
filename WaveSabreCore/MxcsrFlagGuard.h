#pragma once

#include "sys_buildfeatures.h"
#ifdef PROUT_WAVESABRE
namespace WaveSabreCore
{
	class MxcsrFlagGuard
	{
	public:
		MxcsrFlagGuard();
		~MxcsrFlagGuard();

	private:
		unsigned int mxcsrRestore;
	};
}

#endif // PROUT_WAVESABRE