# New ports collection makefile for:   libXdmcp
# Date Created:			28 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXdmcp
PORTVERSION=	0.1.1
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~xlibs/release/:fdo \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	anholt/:local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:fdo \
		Wraphelp2.gz:local

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Display Manager Control Protocol library

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/xproto.pc:${PORTSDIR}/x11/xproto

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack pkgconfig

post-extract:
	${GUNZIP_CMD} -c ${DISTDIR}/Wraphelp2.gz > ${WRKSRC}/Wraphelp.c

.include <bsd.port.mk>
