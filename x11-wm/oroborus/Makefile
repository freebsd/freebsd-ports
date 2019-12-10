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
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg
USE_XORG=	xpm x11 xext sm ice
GNU_CONFIGURE=	yes

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
