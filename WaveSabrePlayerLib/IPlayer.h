#pragma once

namespace WaveSabrePlayerLib
{
	class IPlayer
	{
	public:
		virtual ~IPlayer();

		virtual void Play() = 0;

		virtual int GetTempo() const = 0;
		virtual int GetSampleRate() const = 0;
		virtual double GetLength() const = 0;
		virtual double GetSongPos() const = 0;
	};
}
