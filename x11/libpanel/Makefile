# New ports collection makefile for:	libpanel
# Date created:				10 July 2002
# Whom:					Maxim Soboleb <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libpanel
PORTVERSION=	1.4.2
CATEGORIES=	x11 gnome
MASTER_SITES=	http://people.freebsd.org/~sobomax/
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomelibs
INSTALLS_SHLIB=	yes
MAKE_ENV=	X11BASE="${X11BASE}" LOCALBASE="${LOCALBASE}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libpanel_applet.so.5 ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libpanel_applet.a ${PREFIX}/lib
	${LN} -sf libpanel_applet.so.5 ${PREFIX}/lib/libpanel_applet.so
	${INSTALL_DATA} ${WRKSRC}/applet-widget.h ${WRKSRC}/gnome-panel.h \
		${PREFIX}/include
	${MKDIR} ${PREFIX}/share/gnome/idl
	${INSTALL_DATA} ${WRKSRC}/gnome-panel.idl ${PREFIX}/share/gnome/idl
	${INSTALL_SCRIPT} ${WRKSRC}/appletsConf.sh ${PREFIX}/etc

.include <bsd.port.mk>
