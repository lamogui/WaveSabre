#pragma once

namespace WaveSabreCore
{
	class MxcsrFlagGuard
	{
	public:
		MxcsrFlagGuard();
		~MxcsrFlagGuard();

	private:
		unsigned int mxcsrRestore;
	};
}
