# New ports collection makefile for:	xvkbd
# Date created:		26 November 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xvkbd
PORTVERSION=	2.6
CATEGORIES=	x11
MASTER_SITES=	http://homepage3.nifty.com/tsato/xvkbd/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A virtual keyboard for X applications

MAN1=		xvkbd.1

.if	defined(WITH_ALL)
WITH_XAW3D=	yes
WITH_XTEST=	yes
WITH_I18N=	yes
.endif

.if	defined(WITH_XAW3D)
BUILD_DEPENDS=	${X11BASE}/lib/libXaw3d.a:${PORTSDIR}/x11-toolkits/Xaw3d
.endif

USE_REINPLACE=	yes
USE_IMAKE=	yes

pre-fetch:
		@${ECHO} "The following define controls are available:"
		@${ECHO} "- WITH_XAW3D	- Xaw3d support;"
		@${ECHO} "- WITH_XTEST	- XTEST extesions support;"
		@${ECHO} "- WITH_I18N	- internationalization;"
		@${ECHO} "- WITH_ALL	- all of the above."

.if	defined(WITH_XAW3D)
XK_DEFSUBST +=	-e 's/XCOMM define XAW3D/\#define XAW3D/;'
.endif
.if	defined(WITH_XTEST)
XK_DEFSUBST +=	-e 's/XCOMM define XTEST/\#define XTEST/;'
.endif
.if	defined(WITH_I18N)
XK_DEFSUBST +=	-e 's/XCOMM define I18N/\#define I18N/;'
.endif

.if	defined(XK_DEFSUBST)
post-patch:
		${REINPLACE_CMD} ${XK_DEFSUBST} ${WRKSRC}/Imakefile
.endif

.include <bsd.port.mk>
