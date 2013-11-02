# Created by: Katsura Matsumoto <katsura@cc.okayama-u.ac.jp>
# $FreeBSD$

PORTNAME=	xnodecor
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.42.org/pub/wmx/contrib/
DISTFILES=	xnodecor.c

MAINTAINER=	katsura@cc.osaka-kyoiku.ac.jp
COMMENT=	Utility to set override_redirect in XWindowAttributes to True

NO_WRKSUBDIR=	yes
USE_XORG=	x11
PLIST_FILES=	bin/xnodecor
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

.include <bsd.port.mk>
