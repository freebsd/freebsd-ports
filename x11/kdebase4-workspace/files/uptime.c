/*
    KSysGuard, the KDE System Guard
   
	Copyright (c) 2009 Markus Brueffer <markus@brueffer.de>
    
    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/

#include <time.h>

#include "Command.h"
#include "ksysguardd.h"
#include "uptime.h"

void
initUptime(struct SensorModul* sm)
{
	registerMonitor("system/uptime", "float", printUptime, printUptimeInfo, sm);
}

void
exitUptime(void)
{
	removeMonitor("system/uptime");
}

void
printUptime(const char* c)
{
	struct timespec tp;
	float uptime = 0;

	if (clock_gettime(CLOCK_MONOTONIC, &tp) != -1)
		uptime = tp.tv_sec + tp.tv_nsec/1000000000.0;

	output("%f\n", uptime);
}

void
printUptimeInfo(const char* c)
{
	output("System uptime\t0\t0\ts\n");
}


