#include <extern/WaveSabre/WaveSabreCore/DelayBuffer.h>
#include <extern/WaveSabre/WaveSabreCore/Helpers.h>

#include "extern/Enigma/eshared/system/types.hpp"
#include "extern/Enigma/eshared/system/runtime.hpp"

namespace WaveSabreCore
{
	DelayBuffer::DelayBuffer(float lengthMs)
	{
		buffer = nullptr;
		SetLength(lengthMs);
	}

	DelayBuffer::~DelayBuffer()
	{
		if (buffer) delete[] buffer;
	}

	void DelayBuffer::SetLength(float lengthMs)
	{
		int newLength = (int)((double)lengthMs * Helpers::CurrentSampleRate / 1000.0);
		//int newLength = eFtoL((double)lengthMs * Helpers::CurrentSampleRate / 1000.0);
		if (newLength < 1) newLength = 1;
		if (newLength != length || !buffer)
		{
			auto newBuffer = new float[newLength];
			for (int i = 0; i < newLength; i++) newBuffer[i] = 0.0f;
			currentPosition = 0;
			auto oldBuffer = buffer;
			buffer = newBuffer;
			length = newLength;
			if (oldBuffer) delete[] oldBuffer;
		}
	}

	void DelayBuffer::WriteSample(float sample)
	{
		buffer[currentPosition] = sample;
		currentPosition = (currentPosition + 1) % length;
	}

	float DelayBuffer::ReadSample() const
	{
		return buffer[currentPosition];
	}
}