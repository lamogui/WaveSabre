#pragma once

#include "extern/WaveSabre/WaveSabreCore/Device.h"

namespace WaveSabreCore
{
	class Crusher : public Device
	{
	public:
		enum class ParamIndices
		{
			Vertical,
			Horizontal,

			DryWet,

			NumParams,
		};

		Crusher();

		virtual void Run(double songPosition, float **inputs, float **outputs, int numSamples);

		virtual void SetParam(int index, float value);
		virtual float GetParam(int index) const;

	private:
		float vertical, horizontal;
		float dryWet;

		float phase[2];
		float hold[2];
	};
}
