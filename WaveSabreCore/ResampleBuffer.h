#pragma once

#include "sys_buildfeatures.h"
#ifdef PROUT_WAVESABRE

namespace WaveSabreCore
{
	class ResampleBuffer
	{
	public:
		ResampleBuffer(float lengthMs = 0.0f);
		~ResampleBuffer();

		void SetLength(float lengthMs);
		void SetLengthSamples(int samples);

		void WriteSample(float sample);
		float ReadPosition(float position) const;

	private:
		int length;
		float *buffer;
		int currentPosition;
	};
}


#endif // PROUT_WAVESABRE