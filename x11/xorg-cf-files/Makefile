# New ports collection makefile for:	xorg-cf-files
# Date created:				Nov 18 2006
# Whom:					Dave Grochowski
#
# $FreeBSD$
#

PORTNAME=	xorg-cf-files
PORTVERSION=	1.0.4
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org cf files for use with imake builds

LICENSE=	MIT

XORG_CAT=	util

.include <bsd.port.pre.mk>

post-patch:
		@${REINPLACE_CMD} 's|\(define ExtraXaw[^ ]*\) [$$].*|\1 /**/|' \
			${WRKSRC}/X11.tmpl
.if defined(CC) && ${CC} == "clang"
		${REINPLACE_CMD} -e 's|/usr/bin/cpp|${LOCALBASE}/bin/ucpp|' \
			-e 's|-traditional|-s|' ${WRKSRC}/FreeBSD.cf
.endif

.include <bsd.port.post.mk>
