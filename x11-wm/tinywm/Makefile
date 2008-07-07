# New ports collection makefile for:	tinywm
# Date created:				Jan 10 2005
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	tinywm
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://incise.org/files/dev/
EXTRACT_SUFX=	.tgz

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Ridiculously tiny window manager

PLIST_FILES=	bin/tinywm
USE_XORG=	x11
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|CC)|CC) ${CFLAGS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tinywm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
