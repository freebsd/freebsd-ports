# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	obmenu
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Menu manager for Openbox supporting both static and pipe menus

LICENSE=	GPLv2

USE_GNOME=		pygtk2
USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	obMenu

PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

SUB_FILES=	pkg-message

DESKTOP_ENTRIES="Obmenu" "Menu manager for Openbox" ${PORTNAME} \
		"${PORTNAME}" "Settings;" ""

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

	${LN} -sf ${DATADIR}/mnu48.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
