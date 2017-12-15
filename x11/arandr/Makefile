# Created by: Sofian Brabez <sbz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arandr
PORTVERSION=	0.1.9
CATEGORIES=	x11 deskutils
MASTER_SITES=	http://christian.amsuess.com/tools/arandr/files/ \
		LOCAL/sbz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Another XRandR GUI

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>0.6:textproc/py-docutils@${FLAVOR}
RUN_DEPENDS=	xrandr>0:x11/xrandr \
		${PYTHON_PKGNAMEPREFIX}gtk2>0:x11-toolkits/py-gtk2@${FLAVOR}

OPTIONS_DEFINE=	DOCS

USE_PYTHON=	distutils
USES+=		gettext desktop-file-utils python:2.7

PORTDOCS=	ChangeLog NEWS README TODO

post-patch:
	${REINPLACE_CMD} -i '' 's#share/man#man#' ${WRKSRC}/${PYSETUP}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
