# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	qtile
PORTVERSION=	0.5
CATEGORIES=	x11-wm

MAINTAINER=	wg@FreeBSD.org
COMMENT=	A small, flexible, scriptable tiling window manager written in Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xpyb>0:${PORTSDIR}/x11/xpyb \
		${PYTHON_PKGNAMEPREFIX}cairo>0:${PORTSDIR}/graphics/py-cairo \
		${PYTHON_PKGNAMEPREFIX}gobject>0:${PORTSDIR}/devel/py-gobject \
		${PYTHON_PKGNAMEPREFIX}gtk>0:${PORTSDIR}/x11-toolkits/py-gtk2

USE_GITHUB=	yes
GH_ACCOUNT=	qtile
GH_COMMIT=	dd52b52
GH_TAGNAME=	v0.5

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

PORTDOCS=	CHANGELOG INSTALL.rst LICENSE README.rst TODO.rst

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
