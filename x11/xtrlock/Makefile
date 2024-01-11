PORTNAME=	xtrlock
PORTVERSION=	2.15
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	X Transparent Lock
WWW=		https://salsa.debian.org/debian/xtrlock

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL-3.txt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		cpe localbase tar:xz xorg
CPE_VENDOR=	${PORTNAME}_project
USE_XORG=	x11

LIBS+=		-lX11 -lcrypt

post-patch:
	@${REINPLACE_CMD} -e \
		's|<crypt.h>|<unistd.h>| ; \
		 s|<values.h>|<limits.h>|' ${WRKSRC}/xtrlock.c

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o xtrlock xtrlock.c ${LDFLAGS} ${LIBS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtrlock ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xtrlock.man ${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
