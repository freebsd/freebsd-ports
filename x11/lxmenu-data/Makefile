# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lxmenu-data
PORTVERSION=	0.1.5
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/lxmenu-data%20%28desktop%20menu%29/

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Menu data used by lxpanel

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		gettext gmake localbase tar:xz
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${LOCALBASE} --sysconfdir=${LOCALBASE}/etc

PORTDOCS=	AUTHORS README TODO
OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
