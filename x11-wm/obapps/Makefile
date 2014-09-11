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

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Graphical editor for Openbox application settings

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlib>=0:${PORTSDIR}/x11-toolkits/py-xlib

USE_PYTHON=	yes
USE_WX=		3.0+
WX_COMPS=	python:run
USE_PYDISTUTILS=yes

PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="OBApps" "" ${PORTNAME} \
		"${PORTNAME}" "Settings;" ""

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
