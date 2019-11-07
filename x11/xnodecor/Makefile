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

BROKEN=		unfetchable

NO_WRKSUBDIR=	yes
USES=		xorg
USE_XORG=	x11
PLIST_FILES=	bin/xnodecor

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

.include <bsd.port.mk>
