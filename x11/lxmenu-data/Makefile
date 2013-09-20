# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lxmenu-data
PORTVERSION=	0.1.2
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/lxmenu-data%20%28desktop%20menu%29/lxmenu-data%20${PORTVERSION}/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Menu data used by lxpanel

LICENSE=	GPLv2

USES=		gettext
USE_XORG=	x11 xmu
USE_GNOME=	intltool
USE_AUTOTOOLS=	automake:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${LOCALBASE} --sysconfdir=${LOCALBASE}/etc
USE_GMAKE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS README TODO

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
