# New ports collection makefile for:	libcapplet
# Date created:				10 July 2002
# Whom:					Maxim Soboleb <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11/libcapplet/Makefile,v 1.7 2007/05/19 21:36:29 marcus Exp $
#

PORTNAME=	libcapplet
PORTVERSION=	1.4.0.5
PORTREVISION=	11
CATEGORIES=	x11 gnome
MASTER_SITES=	http://people.freebsd.org/~sobomax/
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A library for writing custom applets for GNOME Control Center

USE_BZIP2=	yes
USE_GNOME=	gnomelibs
USE_LDCONFIG=	yes
MAKE_ENV=	LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800071
BROKEN=		does not build
.endif

post-build:
	@${REINPLACE_CMD} -e 's/-lgnugetopt //' ${WRKSRC}/cappletConf.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libcapplet.so.5 ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libcapplet.a ${PREFIX}/lib
	${LN} -sf libcapplet.so.5 ${PREFIX}/lib/libcapplet.so
	${MKDIR} ${PREFIX}/include/libcapplet1
	${INSTALL_DATA} ${WRKSRC}/capplet-widget.h \
		${PREFIX}/include/libcapplet1
	${MKDIR} ${PREFIX}/share/idl
	${INSTALL_DATA} ${WRKSRC}/control-center.idl ${PREFIX}/share/idl
	${INSTALL_SCRIPT} ${WRKSRC}/cappletConf.sh ${PREFIX}/etc

.include <bsd.port.post.mk>
