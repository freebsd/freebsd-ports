# New ports collection makefile for:	xclass
# Date created:		2004-02-05
# Whom:			patrick@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	xclass
PORTVERSION=	0.8.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xclass

MAINTAINER=	patrick@FreeBSD.org
COMMENT=	C++ layout library for X

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

ALL_TARGET=	shared
INSTALL_TARGET=	install_shared
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.else
BROKEN=		"Broken pkg-plist"
.endif
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2004-06-18

do-install:
	${LN} -sf ${PREFIX}/lib/libxclass.so.0.8.2 ${PREFIX}/lib/libxclass.so

.include <bsd.port.post.mk>
