# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	qtile
PORTVERSION=	0.6
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
USE_PYDISTUTILS=	easy_install

PORTDOCS=	CHANGELOG INSTALL.rst LICENSE README.rst

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
