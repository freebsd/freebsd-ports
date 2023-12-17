PORTNAME=	w9wm
PORTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.drieu.org/code/w9wm/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hack of 9wm to give virtual screens
WWW=		http://www.grassouille.org/code/w9wm.en.html

DEPRECATED=	Last upstream release was in 2002
EXPIRATION_DATE=	2024-01-17

USES=		imake xorg
USE_XORG=	x11 xext

WRKSRC=		${WRKDIR}/${DISTNAME}.orig

PLIST_FILES=	bin/w9wm \
		man/man1/w9wm.1.gz

post-patch:
	@${REINPLACE_CMD} -e '/malloc\.h/d' ${WRKSRC}/client.c

.include <bsd.port.mk>
