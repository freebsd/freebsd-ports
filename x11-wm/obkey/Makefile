# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	obkey
PORTVERSION=	1.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-wm python

USE_GITHUB=	yes
GH_ACCOUNT=	nsf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Openbox hotkey editor, written in Python and PyGTK

LICENSE=	MIT

RUN_DEPENDS=	py27-gtk2>=2.14:x11-toolkits/py-gtk2

USES=		desktop-file-utils gettext python:2.7
USE_PYTHON=	distutils
NO_ARCH=	yes

PORTDOCS=	NEWS

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,python,env &,' \
		${WRKSRC}/obkey ${WRKSRC}/obkey_classes.py
	@${REINPLACE_CMD} -e '/config_prefix/s,/usr,${LOCALBASE},' \
		${WRKSRC}/obkey_classes.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/misc/obkey.desktop ${STAGEDIR}${DESKTOPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
