/*
 ** XvMC extension info program
 **
 ** author:
 ** Michal Podsiadlik <michal (et) gov.one.pl>
 ** Ken Harris : fixed some bugs with the "chroma" and "codec" fields, 2005-10-01
 **
 ** compile using this command (I hope ;-))
 ** gcc -o xvmcinfo xvmcinfo.c -lXvMCW
 * */

#include <stdlib.h>
#include <stdio.h>

#include <X11/Xlib.h>
#include <X11/extensions/XvMClib.h>

void usage(char *c)
{
    fprintf(stderr, "usage:\n" "%s [-display displayname]\n", c);
    exit(1);
}

int main(int argc, char **argv)
{
    Display *xserver;
    int iscreen;
    char *display = NULL;

    if (argc != 1 && argc != 3)
        usage(argv[0]);

    if (argc == 3) {
        if (!strcmp(argv[1], "-display"))
            display = argv[2];
        else
            usage(argv[0]);
    }

    xserver = XOpenDisplay(display);
    if (!xserver) {
        fprintf(stderr, "failed to connect to display: %s\n", display);
        return 1;
    }

    {
        unsigned int xv_major, xv_minor, x, y, z;
        if (XvQueryExtension(xserver, &xv_major, &xv_minor, &x, &y, &z) !=
            Success) {
            fprintf(stderr, "no Xv extension available\n");
            XCloseDisplay(xserver);
            return 1;
        }
        printf("\n" "Xv version %i.%i\n", xv_major, xv_minor);
   }

    {
        int xvmc_major, xvmc_minor;
        if (XvMCQueryVersion(xserver, &xvmc_major, &xvmc_minor) != Success) {
            fprintf(stderr, "no XvMC extension available\n");
            XCloseDisplay(xserver);
            return 1;
        }

        printf("XvMC version %i.%i\n\n", xvmc_major, xvmc_minor);
    }

    for (iscreen = 0; iscreen < ScreenCount(xserver); iscreen++) {
        unsigned int iadapt, num_adaptors;
        XvAdaptorInfo *adaptor_info;

        printf("screen number %i\n", iscreen);

        XvQueryAdaptors(xserver, RootWindow(xserver, iscreen),
                        &num_adaptors, &adaptor_info);

        if (!num_adaptors) {
            printf("   no Xv adaptors found\n");
            continue;
        }

        for (iadapt = 0; iadapt < num_adaptors; iadapt++) {
            int isurf, num_surfaces;
            XvMCSurfaceInfo *xvmc_info;

            printf("   info for adaptor %i [%s]\n", iadapt,
                   adaptor_info[iadapt].name);

            xvmc_info =
                XvMCListSurfaceTypes(xserver, adaptor_info[iadapt].base_id,
                                     &num_surfaces);

            printf("      number of XvMC surface types: %i\n\n",
                   num_surfaces);

            for (isurf = 0; isurf < num_surfaces; isurf++) {
                static char *codec[] = { "", "MPEG1", "MPEG2", "H263", "MPEG4" };       // XXXX HACK
                static char *chroma[] = { "", "XVMC_CHROMA_FORMAT_420 ", "XVMC_CHROMA_FORMAT_422 ", "XVMC_CHROMA_FORMAT_444 " };        // XXXX HACK
                printf("      info about surface %i:\n"
                       "         max_width=%i\n"
                       "         max_height=%i\n"
                       "         subpicture_max_width=%i\n"
                       "         subpicture_max_height=%i\n"
                       "         chroma_format:\n"
                       "            %s\n"
                       "         mc_type:\n"
                       "            format                   : %s\n"
                       "            accelaration start from  : %s\n"
                       "         flags:\n"
                       "            %s%s%s%s\n\n",
                        isurf,
                       xvmc_info[isurf].max_width,
                       xvmc_info[isurf].max_height,
                       xvmc_info[isurf].subpicture_max_width,
                       xvmc_info[isurf].subpicture_max_height,
                       /* chroma_format */
                       chroma[xvmc_info[isurf].chroma_format && 0xf],
                       /* mc_type */
                       codec[xvmc_info[isurf].mc_type && 0xf],
                       /* XVMC_MOCOMP is zero! */
                       xvmc_info[isurf].mc_type & XVMC_MOCOMP ? "motion compensation " : "",
                       xvmc_info[isurf].mc_type & XVMC_IDCT ? "IDCT " : "MOCOMP ",
                       /* flags */
                       xvmc_info[isurf].flags & XVMC_OVERLAID_SURFACE ?  "XVMC_OVERLAID_SURFACE " : "",
                       xvmc_info[isurf].flags & XVMC_BACKEND_SUBPICTURE ?  "XVMC_BACKEND_SUBPICTURE " : "",
                       xvmc_info[isurf].flags & XVMC_SUBPICTURE_INDEPENDENT_SCALING ?  "XVMC_SUBPICTURE_INDEPENDENT_SCALING " : "",
                       xvmc_info[isurf].flags & XVMC_INTRA_UNSIGNED ? "XVMC_INTRA_UNSIGNED " : "");
               }
            XFree(xvmc_info);
        }
        XvFreeAdaptorInfo(adaptor_info);
  }
  XCloseDisplay(xserver);
  return 0;
}
