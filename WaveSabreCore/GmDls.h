#pragma once

#include "sys_buildfeatures.h"
#ifdef PROUT_WAVESABRE

namespace WaveSabreCore
{
	class GmDls
	{
	public:
		static const int WaveListOffset = 0x00044602;
		static const int NumSamples = 495;

		static unsigned char *Load();
	};
}

#endif // PROUT_WAVESABRE