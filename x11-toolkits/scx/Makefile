# New ports collection makefile for:	scx
# Date created:				14 July 2004
# Whom:					bkhl@elektrubadur.se
#
# $FreeBSD$
#

PORTNAME=	scx
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits scheme
MASTER_SITES=	ftp://ftp.scsh.net/pub/scsh/packages/scx/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GUI library for scsh and Scheme 48

RUN_DEPENDS=	${LOCALBASE}/lib/scsh/scsh-install-pkg:${PORTSDIR}/devel/scsh-install-lib

NO_BUILD=	yes
USE_XLIB=	yes
USE_LDCONFIG=	${PREFIX}/lib/scsh/0.6/scx-0.2/lib/${MACHINE_ARCH}-portbld-freebsd${OSREL}/

PLIST_SUB=	TARGET=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' \
			-e 's|echo aout|echo elf|g' \
	${WRKSRC}/configure

do-install:
	(cd ${WRKSRC}; ${LOCALBASE}/lib/scsh/scsh-install-pkg --prefix=${PREFIX}/lib/scsh)

.include <bsd.port.mk>
