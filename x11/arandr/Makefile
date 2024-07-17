PORTNAME=	arandr
PORTVERSION=	0.1.11
CATEGORIES=	x11 deskutils

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Another XRandR GUI
WWW=		https://christian.amsuess.com/tools/arandr/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>0.6:textproc/py-docutils@${PY_FLAVOR}
RUN_DEPENDS=	xrandr>0:x11/xrandr

USES=		gettext gnome python
USE_GITLAB=	yes
GL_TAGNAME=	8348c0b6020a792c1fed5baca923151db98b9397
USE_GNOME=	gtk30 pygobject3
USE_PYTHON=	distutils noflavors py3kplist

NO_ARCH=	yes

PORTDOCS=	ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
