# $Id: Makefile,v 1.43 1995/01/06 02:32:43 asami Exp $
#
SUBDIR= ImageMagick Xaw3d color_xterm ctwm emu fvwm ghostview \
	irsim iv ivs jpeg kterm magic mpeg-lib mpeg_play olvwm pcb \
	piewm povray rxvt tiff tk tkhfs tkman tvtwm x3270 xanim \
	xarchie xcd xcdplayer xdvi xearth xfed xfig xfm xgraph xli \
	xlockmore xpaint xpm xsnow xtexshell \
	xview-config xview-lib xview-clients

#
# These depend on tk, so might as well build tk first...
# (And vic depends on blt.)
#
SUBDIR+= imm nv blt vic

.include <bsd.port.subdir.mk>
