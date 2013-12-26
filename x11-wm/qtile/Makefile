# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	qtile
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Small, flexible, scriptable tiling window manager written in Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xpyb>0:${PORTSDIR}/x11/xpyb \
		${PYTHON_PKGNAMEPREFIX}cairo>0:${PORTSDIR}/graphics/py-cairo

USE_GITHUB=	yes
GH_ACCOUNT=	qtile
GH_COMMIT=	8b133d4
GH_TAGNAME=	v0.6

USE_GNOME=	pygobject pygtk2

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

PORTDOCS=	CHANGELOG INSTALL.rst README.rst

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
