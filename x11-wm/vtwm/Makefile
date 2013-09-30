# Created by: Bruce A. Mah <bmah@ca.sandia.gov>
# $FreeBSD$

PORTNAME=	vtwm
PORTVERSION=	5.4.7
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	SF http://www.vtwm.org/downloads/

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Twm with a virtual desktop and optional Motif-like features

LICENSE=	MIT

USE_XORG=	x11 xext xpm xmu
MAKEFILE=	${FILESDIR}/Makefile.bsd

ETCDIR?=	${PREFIX}/etc

PLIST_FILES=	bin/vtwm \
		etc/system.vtwmrc \
		man/man1/vtwm.1.gz

OPTIONS_DEFINE=	SOUND NLS
OPTIONS_DEFAULT=	SOUND NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOUND}
LIB_DEPENDS+=	librplay.so:${PORTSDIR}/audio/rplay
MAKE_ENV+=	SOUND=yes
.else
MAKE_ENV+=	SOUND=no
.endif

.if ! ${PORT_OPTIONS:MNLS}
CFLAGS+=	-DNO_I18N_SUPPORT
.endif

.include <bsd.port.mk>
