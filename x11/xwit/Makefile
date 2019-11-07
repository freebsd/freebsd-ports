# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xwit
PORTVERSION=	3.4
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	XCONTRIB/utilities:source1 LOCAL/ehaupt:source2
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}:source1 \
		${PORTNAME}-patchset-${PORTVERSION}${EXTRACT_SUFX}:source2

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	X interface tool

USES=		imake xorg
USE_XORG=	x11 xext

PLIST_FILES=	bin/xwit man/man1/xwit.1.gz

EXTRA_PATCHES=	${WRKDIR}/${PORTNAME}-patchset-${PORTVERSION}/patch-*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}._man \
		${STAGEDIR}${MANPREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
