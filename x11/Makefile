# $Id: Makefile,v 1.41 1995/01/04 07:54:48 jkh Exp $
#
SUBDIR= ImageMagick Xaw3d color_xterm ctwm emu fvwm ghostview \
	irsim iv ivs jpeg kterm magic mpeg-lib mpeg_play olvwm pcb \
	piewm povray rxvt tiff tk tkhfs tkman tvtwm x3270 xanim \
	xarchie xcd xcdplayer xdvi xearth xfed xfig xfm xgraph xli \
	xlockmore xminesweep xpaint xpm xsnow xtexshell xv \
	xview-config xview-lib xview-clients

#
# These depend on tk, so might as well build tk first...
# (And vic depends on blt.)
#
SUBDIR+= imm nv blt vic

.include <bsd.port.subdir.mk>
