# Created by: Sofian Brabez <sbz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arandr
PORTVERSION=	0.1.7.1
PORTREVISION=	1
CATEGORIES=	x11 deskutils
MASTER_SITES=	http://christian.amsuess.com/tools/arandr/files/ \
		LOCAL/${MAINTAINER:C/([^@]*)@.*/\1/}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Another XRandR GUI

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>0.6:${PORTSDIR}/textproc/py-docutils
RUN_DEPENDS=	xrandr>0:${PORTSDIR}/x11/xrandr \
		${PYTHON_PKGNAMEPREFIX}gtk2>0:${PORTSDIR}/x11-toolkits/py-gtk2

OPTIONS_DEFINE=	DOCS

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

USES+=		gettext desktop-file-utils

PORTDOCS=	ChangeLog NEWS README TODO

post-patch:
	${REINPLACE_CMD} -i '' 's#share/man#man#' ${WRKSRC}/${PYSETUP}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
