#pragma once

namespace WaveSabreCore
{
	enum class EnvelopeState
	{
		Attack,
		Decay,
		Sustain,
		Release,
		Finished,
	};

	class Envelope
	{
	public:
		Envelope();

		void Trigger();
		void Off();

		float GetValue() const;
		void Next();

		EnvelopeState State;

		float Attack, Decay, Sustain, Release;

	private:
		float pos;
		float releaseValue;
	};
}

