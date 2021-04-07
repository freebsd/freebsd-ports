PORTNAME=	nezd
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose messaging, notification and menuing program for X11

LICENSE=	MIT

USES=		pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	telser

USE_XORG=	x11 xpm xinerama xft

CONFLICTS_INSTALL=	dzen2

OPTIONS_DEFINE=	GADGETS
GADGETS_DESC=	Build and install gadgets
OPTIONS_SUB=	yes

GADGETS_ALL_TARGET=	all gadgets
GADGETS_INSTALL_TARGET=	install install-gadgets

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.nezd ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/gadgets/README.* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
