# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	xvkbd
PORTVERSION=	3.7
CATEGORIES=	x11
MASTER_SITES=	http://homepage3.nifty.com/tsato/xvkbd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual keyboard for X applications

LICENSE=	GPLv2+

USES=		imake
USE_XORG=	ice sm x11 xaw xext xmu xpm xt

DESKTOP_ENTRIES="Xvkbd" "" "" "xvkbd" "Utility;" false

OPTIONS_DEFINE=		DOCS NLS XAW3D XTEST
OPTIONS_DEFAULT=	XTEST

XAW3D_DESC=		Xaw3d widget library support
XAW3D_LIB_DEPENDS=	libXaw3d.so:x11-toolkits/Xaw3d
XTEST_DESC=		XTEST extensions support
XTEST_USE=		xorg=xtst

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/include/|${LOCALBASE}/include/|' ${WRKSRC}/XVkbd-small.ad

post-patch-NLS-on:
	@${REINPLACE_CMD} -e \
		'/define I18N/s|^XCOMM |#|' ${WRKSRC}/Imakefile

post-patch-XAW3D-on:
	@${REINPLACE_CMD} -e \
		'/define XAW3D/s|^XCOMM |#|' ${WRKSRC}/Imakefile

post-patch-XTEST-on:
	@${REINPLACE_CMD} -e \
		'/define XTEST/s|^XCOMM |#|' ${WRKSRC}/Imakefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
