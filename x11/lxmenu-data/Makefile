# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lxmenu-data
PORTVERSION=	0.1.2
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/lxmenu-data%20%28desktop%20menu%29/lxmenu-data%20${PORTVERSION}/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Menu data used by lxpanel

LICENSE=	GPLv2

USES=		gmake gettext
USE_XORG=	x11 xmu
USE_GNOME=	intltool
USE_AUTOTOOLS=	automake:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${LOCALBASE} --sysconfdir=${LOCALBASE}/etc

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS README TODO

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
