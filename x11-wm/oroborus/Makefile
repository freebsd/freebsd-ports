# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oroborus
PORTVERSION=	2.0.20
CATEGORIES=	x11-wm
MASTER_SITES=	DEBIAN/pool/main/o/${PORTNAME} GENTOO
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	matt@peterson.org
COMMENT=	Small and simple GNOME-compatible window manager

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_XORG=	xpm

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	AUTHORS ChangeLog README TODO

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/example.oroborusrc \
		${STAGEDIR}${ETCDIR}rc.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
