# New ports collection makefile for:	xnodecor
# Date created:		15 November 2002
# Whom:			Katsura Matsumoto <katsura@cc.okayama-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xnodecor
PORTVERSION=	0.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.42.org/pub/wmx/contrib/
DISTFILES=	xnodecor.c

MAINTAINER=	katsura@cc.osaka-kyoiku.ac.jp
COMMENT=	Utility to set override_redirect in XWindowAttributes to True

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/xnodecor
USE_X_PREFIX=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

.include <bsd.port.mk>
