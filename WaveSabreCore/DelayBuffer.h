#pragma once

#include "sys_buildfeatures.h"
#ifdef PROUT_WAVESABRE
namespace WaveSabreCore
{
	class DelayBuffer
	{
	public:
		DelayBuffer(float lengthMs = 0.0f);
		~DelayBuffer();

		void SetLength(float lengthMs);

		void WriteSample(float sample);
		float ReadSample() const;

	private:
		int length;
		float *buffer;
		int currentPosition;
	};
}

#endif // PROUT_WAVESABRE