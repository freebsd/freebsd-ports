# $Id: Makefile,v 1.39 1994/12/25 21:39:25 ljo Exp $
#
SUBDIR=	ImageMagick Xaw3d color_xterm ctwm emu fvwm ghostview iv ivs \
	jpeg kterm magic mpeg-lib mpeg_play olvwm \
	pcb piewm rxvt tiff tk tkhfs tvtwm xanim xarchie xcd \
	xcdplayer xdvi xearth xfed xfig xgraph xli xlockmore xpm xsnow \
	xtexshell xv \
	xview-config xview-lib xview-clients

#
# These depend on tk, so might as well build tk first...
# (And vic depends on blt.)
#
SUBDIR+= imm nv blt vic

.include <bsd.port.subdir.mk>
