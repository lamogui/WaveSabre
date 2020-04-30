#pragma once

#include "sys_buildfeatures.h"
#ifdef PROUT_WAVESABRE
#include "extern/WaveSabre/WaveSabreCore/Device.h"
#include "extern/WaveSabre/WaveSabreCore/DelayBuffer.h"

namespace WaveSabreCore
{
	class Smasher : public Device
	{
	public:
		enum class ParamIndices
		{
			Sidechain,
			InputGain,
			Threshold,
			Ratio,
			Attack,
			Release,
			OutputGain,

			NumParams,
		};

		Smasher();
		virtual ~Smasher();

		virtual void Run(double songPosition, float **inputs, float **outputs, int numSamples);

		virtual void SetParam(int index, float value);
		virtual float GetParam(int index) const;

	private:
		const static float lookaheadMs;

		bool sidechain;
		float inputGain;
		float threshold, ratio;
		float attack, release;
		float outputGain;

		DelayBuffer leftBuffer;
		DelayBuffer rightBuffer;
		float peak;
	};
}

#endif // PROUT_WAVESABRE