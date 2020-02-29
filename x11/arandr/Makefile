# Created by: Sofian Brabez <sbz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arandr
PORTVERSION=	0.1.10
CATEGORIES=	x11 deskutils

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Another XRandR GUI

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>0.6:textproc/py-docutils@${PY_FLAVOR}
RUN_DEPENDS=	xrandr>0:x11/xrandr

USES=		gettext gnome python
USE_GITLAB=	yes
GL_COMMIT=	43faec00c0feca3f00b0acbae048de14f02c6d21
USE_GNOME=	pygobject3
USE_PYTHON=	distutils noflavors py3kplist

NO_ARCH=	yes

PORTDOCS=	ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
