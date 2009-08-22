# New ports collection makefile for:   jwm
# Date created:        26 DEC 2005
# Whom:                babak@farrokhi.net
#
# $FreeBSD$
#

PORTNAME=	jwm
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	SF \
		http://joewing.net/programs/


MAINTAINER=	ports@FreeBSD.org
COMMENT=	Joe's Window Manager

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_XORG=	xpm
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		jwm.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/example.jwmrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/jwm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/example.jwmrc ${PREFIX}/etc/system.jwmrc.sample
	if ! [ -f ${PREFIX}/etc/system.jwmrc ]; then \
		${INSTALL_DATA} ${WRKSRC}/example.jwmrc ${PREFIX}/etc/system.jwmrc; \
	fi
	${INSTALL_MAN} ${WRKSRC}/jwm.1 ${MANPREFIX}/man/man1/

.include <bsd.port.post.mk>
