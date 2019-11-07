# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	w9wm
PORTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.drieu.org/code/w9wm/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hack of 9wm to give virtual screens

WRKSRC=		${WRKDIR}/${DISTNAME}.orig

USES=		imake xorg
USE_XORG=	x11 xext

PLIST_FILES=	bin/w9wm \
		man/man1/w9wm.1.gz

post-patch:
	@${REINPLACE_CMD} -e '/malloc\.h/d' ${WRKSRC}/client.c

.include <bsd.port.mk>
