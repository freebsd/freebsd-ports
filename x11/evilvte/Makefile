# New ports collection makefile for:	evilvte
# Date created:				2008/06/03
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	evilvte
PORTVERSION=	0.4.4
PORTREVISION=	3
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	http://www.calno.com/${PORTNAME}/ \
		LOCAL/chinsan/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A VTE based, super lightweight terminal emulator

USE_GMAKE=	yes
USE_GNOME=	vte

MAN1=		evilvte.1 showvte.1

post-patch:
	@${REINPLACE_CMD} -e '40,41 d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|\(FONT_SIZE\).*|\1 12|' ${WRKSRC}/src/config.h

post-install:
# install manual
	${INSTALL_MAN} ${WRKSRC}/misc/evilvte.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/misc/showvte.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
