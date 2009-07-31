# New ports collection makefile for:	simdock
# Date created:				28 Jul 2007
# Whom:					Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	simdock
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast and customizable dockbar

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnomeprefix pkgconfig gconf2 libwnck
USE_WX=		2.8
WX_CONF_ARGS=	absolute

WRKSRC=		${WRKDIR}/trunk

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL LICENSE NEWS README TODO

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/src/main.h
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|g' \
		-e 's|/usr/share/firefox|${PREFIX}/lib/firefox|g' \
		${WRKSRC}/src/main.cc

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
