// Copyright (C) 2003-2009 Dolphin Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official SVN repository and contact information can be found at
// http://code.google.com/p/dolphin-emu/

#include "FileUtil.h"
#include "IniFile.h"
#include "VideoConfig.h"

Config g_Config;

Config::Config()
{
    bFullscreen = false;
    bHideCursor = false;
    renderToMainframe = false;	

    bShowStats = false;
    bDumpTextures = false;
    bDumpObjects = false;
    bDumpFrames = false;
    bDumpTevStages = false;

    bHwRasterizer = false;

    drawStart = 0;
    drawEnd = 100000;
}

void Config::Load()
{
    std::string temp;
    IniFile iniFile;
    iniFile.Load((std::string(File::GetUserPath(D_CONFIG_IDX)) + "gfx_software.ini").c_str());
    
	Section& hardware = iniFile["Hardware"];
    hardware.Get("Fullscreen", &bFullscreen, false); // Hardware
    hardware.Get("RenderToMainframe", &renderToMainframe, false);
}



void Config::Save()
{
    IniFile iniFile;
    iniFile.Load((std::string(File::GetUserPath(D_CONFIG_IDX)) + "gfx_software.ini").c_str());

	Section& hardware = iniFile["Hardware"];
    hardware.Set("Fullscreen", bFullscreen);
    hardware.Set("RenderToMainframe", renderToMainframe);
    
    iniFile.Save((std::string(File::GetUserPath(D_CONFIG_IDX)) + "gfx_opengl.ini").c_str());
}

