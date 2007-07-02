# New ports collection makefile for:    xorg-libraries
# Date created:		29 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-libraries
PORTVERSION=	7.2
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org libraries meta-port

NO_BUILD=	yes

PREFIX?=	${X11BASE}

# Needs: libGL

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/x11.pc:${PORTSDIR}/x11/libX11 \
		${X11BASE}/libdata/pkgconfig/xfont.pc:${PORTSDIR}/x11-fonts/libXfont \
		${X11BASE}/libdata/pkgconfig/xfontcache.pc:${PORTSDIR}/x11-fonts/libXfontcache \
		${X11BASE}/libdata/pkgconfig/ice.pc:${PORTSDIR}/x11/libICE \
		${X11BASE}/libdata/pkgconfig/sm.pc:${PORTSDIR}/x11/libSM \
		${X11BASE}/libdata/pkgconfig/xres.pc:${PORTSDIR}/x11/libXres \
		${X11BASE}/libdata/pkgconfig/xtrap.pc:${PORTSDIR}/x11/libXTrap \
		${X11BASE}/libdata/pkgconfig/xau.pc:${PORTSDIR}/x11/libXau \
		${X11BASE}/libdata/pkgconfig/xaw8.pc:${PORTSDIR}/x11-toolkits/libXaw \
		${X11BASE}/libdata/pkgconfig/xcomposite.pc:${PORTSDIR}/x11/libXcomposite \
		${X11BASE}/libdata/pkgconfig/xcursor.pc:${PORTSDIR}/x11/libXcursor \
		${X11BASE}/libdata/pkgconfig/xdamage.pc:${PORTSDIR}/x11/libXdamage \
		${X11BASE}/libdata/pkgconfig/xdmcp.pc:${PORTSDIR}/x11/libXdmcp \
		${X11BASE}/libdata/pkgconfig/xevie.pc:${PORTSDIR}/x11/libXevie \
		${X11BASE}/libdata/pkgconfig/xext.pc:${PORTSDIR}/x11/libXext \
		${X11BASE}/libdata/pkgconfig/xfixes.pc:${PORTSDIR}/x11/libXfixes \
		${X11BASE}/libdata/pkgconfig/xfont.pc:${PORTSDIR}/x11-fonts/libXfont \
		${X11BASE}/libdata/pkgconfig/xi.pc:${PORTSDIR}/x11/libXi \
		${X11BASE}/libdata/pkgconfig/xinerama.pc:${PORTSDIR}/x11/libXinerama \
		${X11BASE}/libdata/pkgconfig/xmu.pc:${PORTSDIR}/x11-toolkits/libXmu \
		${X11BASE}/libdata/pkgconfig/xp.pc:${PORTSDIR}/x11/libXp \
		${X11BASE}/libdata/pkgconfig/xpm.pc:${PORTSDIR}/x11/libXpm \
		${X11BASE}/libdata/pkgconfig/xrandr.pc:${PORTSDIR}/x11/libXrandr \
		${X11BASE}/libdata/pkgconfig/xrender.pc:${PORTSDIR}/x11/libXrender \
		${X11BASE}/libdata/pkgconfig/xscrnsaver.pc:${PORTSDIR}/x11/libXScrnSaver \
		${X11BASE}/libdata/pkgconfig/xt.pc:${PORTSDIR}/x11-toolkits/libXt \
		${X11BASE}/libdata/pkgconfig/xtst.pc:${PORTSDIR}/x11/libXtst \
		${X11BASE}/libdata/pkgconfig/xv.pc:${PORTSDIR}/x11/libXv \
		${X11BASE}/libdata/pkgconfig/xvmc.pc:${PORTSDIR}/x11/libXvMC \
		${X11BASE}/libdata/pkgconfig/xxf86dga.pc:${PORTSDIR}/x11/libXxf86dga \
		${X11BASE}/libdata/pkgconfig/xxf86misc.pc:${PORTSDIR}/x11/libXxf86misc \
		${X11BASE}/libdata/pkgconfig/xxf86vm.pc:${PORTSDIR}/x11/libXxf86vm \
		${X11BASE}/libdata/pkgconfig/xkbfile.pc:${PORTSDIR}/x11/libxkbfile \
		${X11BASE}/libdata/pkgconfig/xkbui.pc:${PORTSDIR}/x11/libxkbui \
		${X11BASE}/libdata/pkgconfig/xft.pc:${PORTSDIR}/x11-fonts/libXft \
		${X11BASE}/libdata/pkgconfig/xprintutil.pc:${PORTSDIR}/x11/libXprintUtil \
		${X11BASE}/libdata/pkgconfig/xprintapputil.pc:${PORTSDIR}/x11/libXprintAppUtil \
		${X11BASE}/libdata/pkgconfig/fontenc.pc:${PORTSDIR}/x11-fonts/libfontenc \
		${X11BASE}/libdata/pkgconfig/dmx.pc:${PORTSDIR}/x11/libdmx \
		${X11BASE}/libdata/pkgconfig/xtrans.pc:${PORTSDIR}/x11/xtrans \
		${X11BASE}/libdata/pkgconfig/libfs.pc:${PORTSDIR}/x11-fonts/libFS \
		${X11BASE}/libdata/pkgconfig/oldx.pc:${PORTSDIR}/x11/liboldX

.if !defined(XORG_UPGRADE) && !defined(PACKAGE_BUILDING) && exists(/usr/X11R6)
pre-everything::
	@if [ ! -L /usr/X11R6 ]; then \
	    echo -n "/usr/X11R6 exists, but it is not a symlink. "; \
	    echo "Installation cannot proceed."; \
	    echo -n "This looks like an incompletely removed old version "; \
	    echo -n "of X.  In the current version, /usr/X11R6 must be "; \
	    echo -n "a symlink if it exists at all."; \
	    echo -n "Please read ${PORTSDIR}/UPDATING (entry of 20070519) "; \
	    echo -n "for the procedure to upgrade X.org related ports."; \
	    /usr/bin/false; \
	fi
.elif !exists(/usr/X11R6) && !defined(WITHOUT_X11R6_SYMLINK)
pre-everything::
	${LN} -s ${X11BASE} /usr/X11R6 || ${TRUE}
.endif

do-install:
		${MKDIR} ${PREFIX}/libdata/xorg
		${TOUCH} ${PREFIX}/libdata/xorg/libraries

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
