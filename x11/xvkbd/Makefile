# New ports collection makefile for:	xvkbd
# Date created:		26 November 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xvkbd
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://homepage3.nifty.com/tsato/xvkbd/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A virtual keyboard for X applications

MAN1=		xvkbd.1

OPTIONS=	XAW3D	"Xaw3d support" off \
		XTEST	"XTEST extensions support" on \
		I18N	"internationalization" on

USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xpm xt

.include <bsd.port.pre.mk>

.if	defined(WITH_XAW3D)
BUILD_DEPENDS=	${LOCALBASE}/lib/libXaw3d.a:${PORTSDIR}/x11-toolkits/Xaw3d
.endif

.if	defined(WITH_XAW3D)
XK_DEFSUBST +=	-e 's/XCOMM define XAW3D/\#define XAW3D/;'
.endif
.if	defined(WITH_XTEST)
XK_DEFSUBST +=	-e 's/XCOMM define XTEST/\#define XTEST/;'
USE_XORG+=	xtst
.endif
.if	defined(WITH_I18N)
XK_DEFSUBST +=	-e 's/XCOMM define I18N/\#define I18N/;'
.endif

post-patch:
.if	defined(XK_DEFSUBST)
		${REINPLACE_CMD} ${XK_DEFSUBST} ${WRKSRC}/Imakefile
.endif
		${REINPLACE_CMD} -e "s@/usr/include/@${LOCALBASE}/include/@" ${WRKSRC}/XVkbd-small.ad

.if	!defined(NOPORTDOCS)
post-install:
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
