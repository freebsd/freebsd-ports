# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	xvkbd
PORTVERSION=	3.4a
CATEGORIES=	x11
MASTER_SITES=	http://homepage3.nifty.com/tsato/xvkbd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual keyboard for X applications

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	XAW3D XTEST NLS DOCS
OPTIONS_DEFAULT=	XTEST
XAW3D_DESC=	Xaw3d widget library support
XTEST_DESC=	XTEST extensions support

USES=		imake
USE_XORG=	ice sm x11 xaw xext xmu xpm xt

MAN1=		xvkbd.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXAW3D}
LIB_DEPENDS+=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d
XK_DEFSUBST+=	-e 's/XCOMM define XAW3d/\#define XAW3d/;'
.endif

.if ${PORT_OPTIONS:MXTEST}
USE_XORG+=	xtst
XK_DEFSUBST+=	-e 's/XCOMM define XTEST/\#define XTEST/;'
.endif

.if ${PORT_OPTIONS:MNLS}
XK_DEFSUBST+=	-e 's/XCOMM define I18N/\#define I18N/;'
.endif

post-patch:
.if defined(XK_DEFSUBST)
	@${REINPLACE_CMD} ${XK_DEFSUBST} ${WRKSRC}/Imakefile
.endif
	@${REINPLACE_CMD} -e \
		's|/usr/include/|${LOCALBASE}/include/|' ${WRKSRC}/XVkbd-small.ad

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${DOCSDIR})
.endif

.include <bsd.port.mk>
