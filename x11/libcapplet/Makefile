# New ports collection makefile for:	libcapplet
# Date created:				10 July 2002
# Whom:					Maxim Soboleb <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libcapplet
PORTVERSION=	1.4.0.5
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
	${INSTALL_PROGRAM} ${WRKSRC}/libcapplet.so.5 ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libcapplet.a ${PREFIX}/lib
	${LN} -sf libcapplet.so.5 ${PREFIX}/lib/libcapplet.so
	${MKDIR} ${PREFIX}/include/libcapplet1
	${INSTALL_DATA} ${WRKSRC}/capplet-widget.h \
		${PREFIX}/include/libcapplet1
	${MKDIR} ${PREFIX}/share/gnome/idl
	${INSTALL_DATA} ${WRKSRC}/control-center.idl ${PREFIX}/share/gnome/idl
	${INSTALL_SCRIPT} ${WRKSRC}/cappletConf.sh ${PREFIX}/etc

.include <bsd.port.mk>
