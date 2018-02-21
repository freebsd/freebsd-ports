# Created by: Tommy Scheunemann <net@arrishq.org>
# $FreeBSD$

PORTNAME=	wmconfig
PORTVERSION=	1.5.0
CATEGORIES=	x11-wm
MASTER_SITES=	https://www.arrishq.net/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Menu generation tool for X window managers

LICENSE=	GPLv2

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog COPYING README TODO

OPTIONS_DEFINE=	NLS DOCS

OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=nls
NLS_CPPFLAGS=	-I${LOCALBASE}/include
NLS_LDFLAGS=	-L${LOCALBASE}/lib
NLS_USES=	gettext

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
