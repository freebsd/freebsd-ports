# $Id: Makefile,v 1.37 1994/12/14 23:02:26 wollman Exp $
#
SUBDIR=	ImageMagick Xaw3d color_xterm ctwm emu fvwm ghostview iv ivs \
	jpeg kterm mpeg-lib mpeg_play olvwm \
	pcb piewm rxvt tiff tk tkhfs tvtwm xanim xarchie \
	xcdplayer xdvi xearth xfed xfig xgraph xli xlockmore xpm xsnow \
	xtexshell xv

#
# These depend on tk, so might as well build tk first...
# (And vic depends on blt.)
#
SUBDIR+= imm nv blt vic

.include <bsd.port.subdir.mk>
