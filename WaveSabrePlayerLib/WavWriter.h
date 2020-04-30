#pragma once

#include "sys_buildfeatures.h"
#ifdef PROUT_WAVESABRE
#ifndef PROUT_RELEASE
#include <stdio.h> // TODO remove STD lib

#include "extern/WaveSabre/WaveSabrePlayerLib/SongRenderer.h"

namespace WaveSabrePlayerLib
{
	class WavWriter
	{
	public:
		typedef void (*ProgressCallback)(double progress, void *data);

		WavWriter(const SongRenderer::Song *song, int numRenderThreads);
		~WavWriter();

		void Write(const char *fileName, ProgressCallback callback, void *data);

	private:
		static void writeInt(int i, FILE *file);
		static void writeShort(short s, FILE *file);

		SongRenderer *songRenderer;
	};
}
#endif // PROUT_RELEASE
#endif // PROUT_WAVESABRE