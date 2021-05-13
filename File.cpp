/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

#include "main.h"

int EraseCacheFiles()
{

	CHAR path[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH,path);

	CHAR szSearch[MAX_PATH];
	memset(szSearch,0x00,MAX_PATH);

	strcpy_s(szSearch,path);
	PathAppendA(szSearch, "\\*.dat");

	WIN32_FIND_DATAA FindFileData;
	HANDLE  hFind = FindFirstFileA(szSearch, &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			char FilePath[MAX_PATH];
			memset(FilePath,0x00,MAX_PATH);

			strcpy_s(FilePath,path);
			PathAppendA(FilePath, FindFileData.cFileName);
			DeleteFileA(FilePath);

		}
		while (FindNextFileA(hFind, &FindFileData));

		FindClose(hFind);
	}

	return 0;
}