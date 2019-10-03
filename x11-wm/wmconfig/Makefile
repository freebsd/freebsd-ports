# Created by: Tommy Scheunemann <net@arrishq.org>
# $FreeBSD$

PORTNAME=	wmconfig
PORTVERSION=	1.5.1
CATEGORIES=	x11-wm
MASTER_SITES=	https://www.arrishq.net/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Menu generation tool for X window managers

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog README TODO

OPTIONS_DEFINE=	NLS DOCS

OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=nls
NLS_USES=	gettext localbase:ldflags

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
