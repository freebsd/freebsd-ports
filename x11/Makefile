# $Id: Makefile,v 1.44 1995/01/06 05:42:02 jkh Exp $
#
SUBDIR= Xaw3d color_xterm ctwm emu fvwm kterm olvwm piewm rxvt tk \
	tkhfs tkman tvtwm x3270 xearth xfed xlockmore xsnow \
	xview-config xview-lib xview-clients

#
# These depend on tk, so might as well build tk first...
# (And vic depends on blt.)
#
SUBDIR+= blt vic

.include <bsd.port.subdir.mk>
