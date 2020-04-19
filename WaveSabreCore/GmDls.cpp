
#include "platforms/win32/sys_win32.h"

#include <extern/WaveSabre/WaveSabreCore/GmDls.h>


static const char *gmDlsPaths[2] =
{
	"drivers/gm.dls",
	"drivers/etc/gm.dls"
};

namespace WaveSabreCore
{
	unsigned char *GmDls::Load()
	{
		HANDLE gmDlsFile = INVALID_HANDLE_VALUE;
		for (int i = 0; gmDlsFile == INVALID_HANDLE_VALUE; i++)
		{
			OFSTRUCT reOpenBuff;
			gmDlsFile = (HANDLE)OpenFile(gmDlsPaths[i], &reOpenBuff, OF_READ); // TODO find a way to suppress warning C4312 on x64
		}

		auto gmDlsFileSize = GetFileSize(gmDlsFile, NULL);
		auto gmDls = new unsigned char[gmDlsFileSize];
		unsigned int bytesRead;
		ReadFile(gmDlsFile, gmDls, gmDlsFileSize, (LPDWORD)&bytesRead, NULL);
		CloseHandle(gmDlsFile);

		return gmDls;
	}
}
