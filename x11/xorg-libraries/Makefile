# New ports collection makefile for:    xorg-libraries
# Date created:		29 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-libraries
PORTVERSION=	7.5.1
CATEGORIES=	x11
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org libraries meta-port

NO_BUILD=	yes

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dmx.pc:${PORTSDIR}/x11/libdmx \
		${LOCALBASE}/libdata/pkgconfig/fontenc.pc:${PORTSDIR}/x11-fonts/libfontenc \
		${LOCALBASE}/libdata/pkgconfig/ice.pc:${PORTSDIR}/x11/libICE \
		${LOCALBASE}/libdata/pkgconfig/libfs.pc:${PORTSDIR}/x11-fonts/libFS \
		${LOCALBASE}/libdata/pkgconfig/oldx.pc:${PORTSDIR}/x11/liboldX \
		${LOCALBASE}/libdata/pkgconfig/pixman-1.pc:${PORTSDIR}/x11/pixman \
		${LOCALBASE}/libdata/pkgconfig/sm.pc:${PORTSDIR}/x11/libSM \
		${LOCALBASE}/libdata/pkgconfig/x11.pc:${PORTSDIR}/x11/libX11 \
		${LOCALBASE}/libdata/pkgconfig/xau.pc:${PORTSDIR}/x11/libXau \
		${LOCALBASE}/libdata/pkgconfig/xaw7.pc:${PORTSDIR}/x11-toolkits/libXaw \
		${LOCALBASE}/libdata/pkgconfig/xcomposite.pc:${PORTSDIR}/x11/libXcomposite \
		${LOCALBASE}/libdata/pkgconfig/xcursor.pc:${PORTSDIR}/x11/libXcursor \
		${LOCALBASE}/libdata/pkgconfig/xdamage.pc:${PORTSDIR}/x11/libXdamage \
		${LOCALBASE}/libdata/pkgconfig/xdmcp.pc:${PORTSDIR}/x11/libXdmcp \
		${LOCALBASE}/libdata/pkgconfig/xevie.pc:${PORTSDIR}/x11/libXevie \
		${LOCALBASE}/libdata/pkgconfig/xext.pc:${PORTSDIR}/x11/libXext \
		${LOCALBASE}/libdata/pkgconfig/xfixes.pc:${PORTSDIR}/x11/libXfixes \
		${LOCALBASE}/libdata/pkgconfig/xfont.pc:${PORTSDIR}/x11-fonts/libXfont \
		${LOCALBASE}/libdata/pkgconfig/xfont.pc:${PORTSDIR}/x11-fonts/libXfont \
		${LOCALBASE}/libdata/pkgconfig/xfontcache.pc:${PORTSDIR}/x11-fonts/libXfontcache \
		${LOCALBASE}/libdata/pkgconfig/xft.pc:${PORTSDIR}/x11-fonts/libXft \
		${LOCALBASE}/libdata/pkgconfig/xi.pc:${PORTSDIR}/x11/libXi \
		${LOCALBASE}/libdata/pkgconfig/xinerama.pc:${PORTSDIR}/x11/libXinerama \
		${LOCALBASE}/libdata/pkgconfig/xkbfile.pc:${PORTSDIR}/x11/libxkbfile \
		${LOCALBASE}/libdata/pkgconfig/xkbui.pc:${PORTSDIR}/x11/libxkbui \
		${LOCALBASE}/libdata/pkgconfig/xmu.pc:${PORTSDIR}/x11-toolkits/libXmu \
		${LOCALBASE}/libdata/pkgconfig/xpm.pc:${PORTSDIR}/x11/libXpm \
		${LOCALBASE}/libdata/pkgconfig/xrandr.pc:${PORTSDIR}/x11/libXrandr \
		${LOCALBASE}/libdata/pkgconfig/xrender.pc:${PORTSDIR}/x11/libXrender \
		${LOCALBASE}/libdata/pkgconfig/xres.pc:${PORTSDIR}/x11/libXres \
		${LOCALBASE}/libdata/pkgconfig/xscrnsaver.pc:${PORTSDIR}/x11/libXScrnSaver \
		${LOCALBASE}/libdata/pkgconfig/xt.pc:${PORTSDIR}/x11-toolkits/libXt \
		${LOCALBASE}/libdata/pkgconfig/xtrans.pc:${PORTSDIR}/x11/xtrans \
		${LOCALBASE}/libdata/pkgconfig/xtrap.pc:${PORTSDIR}/x11/libXTrap \
		${LOCALBASE}/libdata/pkgconfig/xtst.pc:${PORTSDIR}/x11/libXtst \
		${LOCALBASE}/libdata/pkgconfig/xv.pc:${PORTSDIR}/x11/libXv \
		${LOCALBASE}/libdata/pkgconfig/xvmc.pc:${PORTSDIR}/x11/libXvMC \
		${LOCALBASE}/libdata/pkgconfig/xxf86dga.pc:${PORTSDIR}/x11/libXxf86dga \
		${LOCALBASE}/libdata/pkgconfig/xxf86misc.pc:${PORTSDIR}/x11/libXxf86misc \
		${LOCALBASE}/libdata/pkgconfig/xxf86vm.pc:${PORTSDIR}/x11/libXxf86vm

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
pre-install::
	${LN} -s ${LOCALBASE} /usr/X11R6 || ${TRUE}
.endif

do-install:
		${MKDIR} ${PREFIX}/libdata/xorg
		${TOUCH} ${PREFIX}/libdata/xorg/libraries

.if !defined(PACKAGE_BUILDING)
post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
