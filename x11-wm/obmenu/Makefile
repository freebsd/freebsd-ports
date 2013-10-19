# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	obmenu
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Menu manager for Openbox supporting both static and pipe menus

LICENSE=	GPLv2

USE_GNOME=		pygtk2
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	obMenu

PORTDOCS=	README

SUB_FILES=	pkg-message

DESKTOP_ENTRIES="Obmenu" "Menu manager for Openbox" ${PORTNAME} \
		"${PORTNAME}" "Settings;" false

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif
	${LN} -sf ${DATADIR}/mnu48.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
