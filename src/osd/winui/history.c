/***************************************************************************

  M.A.M.E.UI  -  Multiple Arcade Machine Emulator with User Interface
  Win32 Portions Copyright (C) 1997-2003 Michael Soderstrom and Chris Kirmse,
  Copyright (C) 2003-2007 Chris Kirmse and the MAME32/MAMEUI team.

  This file is part of MAMEUI, and may only be used, modified and
  distributed under the terms of the MAME license, in "readme.txt".
  By continuing to use, modify or distribute this file you indicate
  that you have read the license and understand and accept it fully.

 ***************************************************************************/

/***************************************************************************

  history.c

    history functions.

***************************************************************************/
// standard windows headers
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>

// MAME/MAMEUI headers
#include "emu.h"
#include "drivenum.h"
#include "mui_util.h"
#include "datafile.h"
#include "history.h"


/**************************************************************
 * functions
 **************************************************************/

// Load indexes from history.dat if found
char * GetGameHistory(int driver_index)
{
	static char dataBuf[2048 * 2048];
	static char buffer[2048 * 2048];
	buffer[0] = '\0';
	dataBuf[0] = '\0';

	if (load_driver_history(&driver_list::driver(driver_index), buffer, ARRAY_LENGTH(buffer)) == 0)
		strcat(dataBuf, buffer);

	if (load_driver_mameinfo(&driver_list::driver(driver_index), buffer, ARRAY_LENGTH(buffer)) == 0)
		strcat(dataBuf, buffer);

	if (load_driver_drivinfo(&driver_list::driver(driver_index), buffer, ARRAY_LENGTH(buffer)) == 0)
		strcat(dataBuf, buffer);

	return ConvertToWindowsNewlines(dataBuf);
}