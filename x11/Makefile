# $Id: Makefile,v 1.40 1994/12/25 23:20:19 ats Exp $
#
SUBDIR=	ImageMagick Xaw3d color_xterm ctwm emu fvwm ghostview iv ivs \
	jpeg kterm magic mpeg-lib mpeg_play olvwm \
	pcb piewm rxvt tiff tk tkhfs tvtwm xanim xarchie xcd \
	xcdplayer xdvi xearth xfed xfig xfm xgraph xli xlockmore xpm xsnow \
	xpaint xtexshell xv \
	xview-config xview-lib xview-clients

#
# These depend on tk, so might as well build tk first...
# (And vic depends on blt.)
#
SUBDIR+= imm nv blt vic

.include <bsd.port.subdir.mk>
