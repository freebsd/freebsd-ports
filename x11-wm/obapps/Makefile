# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	obapps
PORTVERSION=	0.1.7
PORTREVISION=	5
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical editor for Openbox application settings

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlib>=0:x11-toolkits/py-xlib@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils
USE_WX=		3.0+
WX_COMPS=	python:run
NO_ARCH=	yes

PORTDOCS=	README

DESKTOP_ENTRIES="OBApps" "" ${PORTNAME} \
		"${PORTNAME}" "Settings;" ""

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
