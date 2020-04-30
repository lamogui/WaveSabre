#pragma once

#include "sys_buildfeatures.h"
#ifdef PROUT_WAVESABRE

namespace WaveSabreCore
{
	class AllPassDelay
	{
	public:
		AllPassDelay();

		void Delay(float delay);
		float Update(float inSamp);

	private:
		float a1, zm1;
	};
}

#endif // PROUT_WAVESABRE