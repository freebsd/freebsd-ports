PORTNAME=	xvkbd
PORTVERSION=	4.1
CATEGORIES=	x11
MASTER_SITES=	http://t-sato.in.coocan.jp/xvkbd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual keyboard for X applications

LICENSE=	GPLv2+

USES=		gmake pkgconfig xorg
USE_XORG=	x11 xaw xmu xt xtst

DESKTOP_ENTRIES="Xvkbd" "" "" "xvkbd" "Utility;" false

OPTIONS_DEFINE=		DOCS

GNU_CONFIGURE=		yes
XAW3D_DESC=		Xaw3d widget library support
XAW3D_LIB_DEPENDS=	libXaw3d.so:x11-toolkits/Xaw3d
XTEST_DESC=		XTEST extensions support
XTEST_USES=		xorg
XTEST_USE=		xorg=xtst

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/include/|${LOCALBASE}/include/|' ${WRKSRC}/XVkbd-small.ad

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
