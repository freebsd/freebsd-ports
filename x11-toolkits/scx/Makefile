# New ports collection makefile for:	scx
# Date created:				14 July 2004
# Whom:					bkhl@elektrubadur.se
#
# $FreeBSD$
#

PORTNAME=	scx
PORTVERSION=	0.2
CATEGORIES=	x11-toolkits scheme
MASTER_SITES=	ftp://ftp.scsh.net/pub/scsh/packages/scx/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GUI library for scsh and Scheme 48

RUN_DEPENDS=	${LOCALBASE}/lib/scsh/scsh-install-pkg:${PORTSDIR}/devel/scsh-install-lib

NO_BUILD=	yes
USE_XLIB=	yes

PLIST_SUB=	TARGET=${MACHINE_ARCH}-portbld-freebsd${OSREL}

do-install:
	(cd ${WRKSRC}; ${LOCALBASE}/lib/scsh/scsh-install-pkg --prefix=${PREFIX}/lib/scsh)

.include <bsd.port.mk>
