# Created by: Tommy Scheunemann <net@arrishq.org>
# $FreeBSD$

PORTNAME=	wmconfig
PORTVERSION=	1.4.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.arrishq.net/files/

MAINTAINER=	net@arrishq.net
COMMENT=	Menu generation tool for X window managers

LICENSE=	GPLv2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog COPYING README TODO

OPTIONS_DEFINE=	NLS DOCS

OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=nls
NLS_CPPFLAGS=	-I${LOCALBASE}/include
NLS_LDFLAGS=	-L${LOCALBASE}/lib
NLS_USES=	gettext

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
