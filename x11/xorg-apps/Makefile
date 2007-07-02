# New ports collection makefile for:    xorg-apps
# Date created:				Jun 22 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xorg-apps
PORTVERSION=	7.2
CATEGORIES=	x11
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org apps meta-port

PREFIX?=	${X11BASE}

RUN_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
		appres:${PORTSDIR}/x11/appres \
		beforelight:${PORTSDIR}/x11/beforelight \
		bitmap:${PORTSDIR}/x11/bitmap \
		editres:${PORTSDIR}/x11/editres \
		fonttosfnt:${PORTSDIR}/x11-fonts/fonttosfnt \
		fslsfonts:${PORTSDIR}/x11-fonts/fslsfonts \
		fstobdf:${PORTSDIR}/x11/fstobdf \
		iceauth:${PORTSDIR}/x11/iceauth \
		ico:${PORTSDIR}/x11/ico \
		listres:${PORTSDIR}/x11/listres \
		luit:${PORTSDIR}/x11/luit \
		${PREFIX}/sbin/mkcomposecache:${PORTSDIR}/x11/mkcomposecache \
		oclock:${PORTSDIR}/x11/oclock \
		showrgb:${PORTSDIR}/x11/rgb \
		rstart:${PORTSDIR}/x11/rstart \
		xon:${PORTSDIR}/x11/scripts \
		sessreg:${PORTSDIR}/x11/sessreg \
		setxkbmap:${PORTSDIR}/x11/setxkbmap \
		showfont:${PORTSDIR}/x11-fonts/showfont \
		smproxy:${PORTSDIR}/x11/smproxy \
		twm:${PORTSDIR}/x11-wm/twm \
		viewres:${PORTSDIR}/x11/viewres \
		x11perf:${PORTSDIR}/x11/x11perf \
		xauth:${PORTSDIR}/x11/xauth \
		xbiff:${PORTSDIR}/x11/xbiff \
		xcalc:${PORTSDIR}/x11/xcalc \
		xclipboard:${PORTSDIR}/x11/xclipboard \
		xclock:${PORTSDIR}/x11/xclock \
		xcmsdb:${PORTSDIR}/x11/xcmsdb \
		xconsole:${PORTSDIR}/x11/xconsole \
		xcursorgen:${PORTSDIR}/x11/xcursorgen \
		xdbedizzy:${PORTSDIR}/x11/xdbedizzy \
		xditview:${PORTSDIR}/x11/xditview \
		xdm:${PORTSDIR}/x11/xdm \
		xdpyinfo:${PORTSDIR}/x11/xdpyinfo \
		xdriinfo:${PORTSDIR}/x11/xdriinfo \
		xedit:${PORTSDIR}/x11/xedit \
		xev:${PORTSDIR}/x11/xev \
		xeyes:${PORTSDIR}/x11/xeyes \
		dga:${PORTSDIR}/x11/xf86dga \
		xfd:${PORTSDIR}/x11/xfd \
		xfindproxy:${PORTSDIR}/x11/xfindproxy \
		xfontsel:${PORTSDIR}/x11-fonts/xfontsel \
		xfs:${PORTSDIR}/x11-fonts/xfs \
		xfsinfo:${PORTSDIR}/x11-fonts/xfsinfo \
		xfwp:${PORTSDIR}/x11/xfwp \
		xgamma:${PORTSDIR}/x11/xgamma \
		xgc:${PORTSDIR}/x11/xgc \
		xhost:${PORTSDIR}/x11/xhost \
		xinit:${PORTSDIR}/x11/xinit \
		xkbcomp:${PORTSDIR}/x11/xkbcomp \
		xkbevd:${PORTSDIR}/x11/xkbevd \
		xkbprint:${PORTSDIR}/x11/xkbprint \
		xkbvleds:${PORTSDIR}/x11/xkbutils \
		xkill:${PORTSDIR}/x11/xkill \
		xload:${PORTSDIR}/x11/xload \
		xlogo:${PORTSDIR}/x11/xlogo \
		xlsatoms:${PORTSDIR}/x11/xlsatoms \
		xlsclients:${PORTSDIR}/x11/xlsclients \
		xlsfonts:${PORTSDIR}/x11-fonts/xlsfonts \
		xmag:${PORTSDIR}/x11/xmag \
		xman:${PORTSDIR}/x11/xman \
		xmessage:${PORTSDIR}/x11/xmessage \
		xmh:${PORTSDIR}/x11/xmh \
		xmodmap:${PORTSDIR}/x11/xmodmap \
		xmore:${PORTSDIR}/x11/xmore \
		xphelloworld:${PORTSDIR}/x11/xphelloworld \
		xplsprinters:${PORTSDIR}/x11/xplsprinters \
		xpr:${PORTSDIR}/x11/xpr \
		xprehashprinterlist:${PORTSDIR}/x11/xprehashprinterlist \
		xprop:${PORTSDIR}/x11/xprop \
		xrandr:${PORTSDIR}/x11/xrandr \
		xrdb:${PORTSDIR}/x11/xrdb \
		xrefresh:${PORTSDIR}/x11/xrefresh \
		xrx:${PORTSDIR}/x11/xrx \
		xset:${PORTSDIR}/x11/xset \
		xsetmode:${PORTSDIR}/x11/xsetmode \
		xsetpointer:${PORTSDIR}/x11/xsetpointer \
		xsetroot:${PORTSDIR}/x11/xsetroot \
		xstdcmap:${PORTSDIR}/x11/xstdcmap \
		xtrapchar:${PORTSDIR}/x11/xtrap \
		xvidtune:${PORTSDIR}/x11/xvidtune \
		xvinfo:${PORTSDIR}/x11/xvinfo \
		xwd:${PORTSDIR}/x11/xwd \
		xwininfo:${PORTSDIR}/x11/xwininfo \
		xwud:${PORTSDIR}/x11/xwud \
		xterm:${PORTSDIR}/x11/xterm

.if exists(/usr/bin/rsh)
RUN_DEPENDS+=	xsm:${PORTSDIR}/x11/xsm
.endif

NO_BUILD=	yes

do-install:
		${MKDIR} ${PREFIX}/libdata/xorg
		${TOUCH} ${PREFIX}/libdata/xorg/apps

.include <bsd.port.mk>
