# $Id: Makefile,v 1.45 1995/01/13 14:19:58 jkh Exp $
#
SUBDIR= Xaw3d color_xterm ctwm emu fvwm kterm olvwm piewm rxvt tk \
	tkhfs tkman tvtwm x3270 xearth xfed xkeycaps xlockmore xsnow \
	xview-config xview-lib xview-clients

#
# These depend on tk, so might as well build tk first...
# (And vic depends on blt.)
#
SUBDIR+= blt vic

.include <bsd.port.subdir.mk>
