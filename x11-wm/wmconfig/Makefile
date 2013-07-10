# Created by: Tommy Scheunemann <net@arrishq.org>
# $FreeBSD$

PORTNAME=	wmconfig
PORTVERSION=	1.4.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.arrishq.net/files/

MAINTAINER=	net@arrishq.net
COMMENT=	Menu generation tool for X window managers

LICENSE=	GPLv2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

MAN1=		wmconfig.1x

PORTDOCS=	AUTHORS ChangeLog COPYING README TODO

OPTIONS_DEFINE=	NLS DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
