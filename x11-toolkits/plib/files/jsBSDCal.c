/*
 * Copyright (C) 2005 Jean-Yves Lefort <jylefort@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/joystick.h>

#define N_ELEMENTS(arr)	(sizeof(arr) / sizeof((arr)[0]))

typedef struct
{
  int	min;
  int	center;
  int	max;
} Axis;

typedef struct
{
  int	n;
  int	fd;
  Axis	axes[2];
} Joystick;

static Joystick joysticks[2];

static void
get_position (Joystick *joy, int *x, int *y)
{
  int b1 = -1;
  int b2 = -1;

  *x = 0;
  *y = 0;

  while (1)
    {
      struct joystick data;

      if (read(joy->fd, &data, sizeof(data)) == sizeof(data))
	{
	  if ((data.b1 && b1 == 0) || (data.b2 && b2 == 0))
	    break;

	  b1 = data.b1;
	  b2 = data.b2;

	  if (data.x > -1000000000)
	    *x = data.x;
	  if (data.y > -1000000000)
	    *y = data.y;
	}

      printf("\rCurrent position: (%10i,%10i)", *x, *y);
      fflush(stdout);

      usleep(50000);
    }

  printf("\n");
}

static void
handle_axis_reversal (Axis *axis)
{
  if (axis->min > axis->max)
    {
      int tmp;

      tmp = axis->min;
      axis->min = axis->max;
      axis->max = tmp;
    }
}

static void
calibrate_joystick (Joystick *joy)
{
  int n = joy->n + 1;

  printf("Move joystick %i to the lower left corner and press any button.\n", n);
  get_position(joy, &joy->axes[0].min, &joy->axes[1].min);

  printf("Center joystick %i and press any button.\n", n);
  get_position(joy, &joy->axes[0].center, &joy->axes[1].center);

  printf("Move joystick %i to the upper right corner and press any button.\n", n);
  get_position(joy, &joy->axes[0].max, &joy->axes[1].max);

  handle_axis_reversal(&joy->axes[0]);
  handle_axis_reversal(&joy->axes[1]);
}

int
main (int argc, char **argv)
{
  int joy_count = 0;
  Joystick *joy;
  int n;
  char *home;

  home = getenv("HOME");
  if (! home)
    {
      fprintf(stderr, "$HOME environment variable not set.\n");
      exit(1);
    }

  for (joy = &joysticks[0], n = 0; n < N_ELEMENTS(joysticks); joy++, n++)
    {
      char devname[PATH_MAX];

      joy->n = n;

      snprintf(devname, sizeof(devname), "/dev/joy%i", n);
      joy->fd = open(devname, O_RDONLY);

      if (joy->fd < 0)
	printf("Cannot open joystick %s: %s\n", devname, strerror(errno));
      else
	{
	  joy_count++;
	  calibrate_joystick(joy);
	  close(joy->fd);
	}
    }

  if (joy_count == 0)
    {
      fprintf(stderr, "No joystick was found.\n");
      exit(1);
    }

  for (joy = &joysticks[0], n = 0; n < N_ELEMENTS(joysticks); joy++, n++)
    if (joy->fd >= 0)
      {
	FILE *f;
	char filename[PATH_MAX];

	snprintf(filename, sizeof(filename), "%s/.joy%irc", home, joy->n);
	f = fopen(filename, "w");

	if (! f)
	  {
	    fprintf(stderr, "Unable to open %s for writing: %s.\n", filename, strerror(errno));
	    exit(1);
	  }

	if (fprintf(f, "16 %i %i %i %i %i %i",
		    joy->axes[0].min, joy->axes[0].center, joy->axes[0].max,
		    joy->axes[1].min, joy->axes[1].center, joy->axes[1].max) < 0)
	  {
	    fprintf(stderr, "Unable to write %s: %s.\n", filename, strerror(errno));
	    exit(1);
	  }

	if (fclose(f) != 0)
	  {
	    fprintf(stderr, "Unable to close %s: %s.\n", filename, strerror(errno));
	    exit(1);
	  }

	printf("Wrote %s.\n", filename);
      }

  return 0;
}
