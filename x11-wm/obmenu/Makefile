# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	obmenu
PORTVERSION=	1.0
PORTREVISION=	8
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Menu manager for Openbox supporting both static and pipe menus

LICENSE=	GPLv2

USES=			python shebangfix
USE_GNOME=		pygtk2
USE_PYTHON=		distutils
PYDISTUTILS_PKGNAME=	obMenu
SHEBANG_FILES=		obmenu obxml.py pipes/obm-xdg
NO_ARCH=		yes

PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

SUB_FILES=	pkg-message

DESKTOP_ENTRIES="Obmenu" "Menu manager for Openbox" ${PORTNAME} \
		"${PORTNAME}" "Settings;" ""

post-patch:
	@${REINPLACE_CMD} -e '/itm.nodeName.lower()/s|execute|command|; \
		/self.dom.createElement("execute")/s|execute|command|; \
		/xml.dom.minidom.Element("execute")/s|execute|command|; \
		/i.nodeName == "execute"/s|execute|command|' \
		${WRKSRC}/obxml.py
	@${REINPLACE_CMD} -e '/import/{p;s|.*|import signal|;}; \
		/os.kill/s|12)|signal.SIGUSR2)|' \
		${WRKSRC}/obmenu

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

	${LN} -sf ${DATADIR}/mnu48.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
