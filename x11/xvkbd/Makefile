# New ports collection makefile for:	xvkbd
# Date created:		26 November 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xvkbd
PORTVERSION=	1.1
CATEGORIES=	x11
MASTER_SITES=	http://member.nifty.ne.jp/tsato/xvkbd/

MAINTAINER=	roam@FreeBSD.org

.if	defined(WITH_XAW3D)
BUILD_DEPENDS=	${X11BASE}/lib/libXaw3d.a:${PORTSDIR}/x11-toolkits/Xaw3d
.endif

USE_IMAKE=	yes

pre-fetch:
		@${ECHO} "The following define controls are available:"
		@${ECHO} "- WITH_XAW3D	- Xaw3d support;"
		@${ECHO} "- WITH_XTEST	- XTEST extesions support;"
		@${ECHO} "- WITH_I18N	- internationalization."

post-patch:
.if	defined(WITH_XAW3D)
		${PERL} -pi.fbsd -e 's/XCOMM define XAW3D/#define XAW3D/' ${WRKSRC}/Imakefile
.endif
.if	defined(WITH_XTEST)
		${PERL} -pi.fbsd -e 's/XCOMM define XTEST/#define XTEST/' ${WRKSRC}/Imakefile
.endif
.if	defined(WITH_I18N)
		${PERL} -pi.fbsd -e 's/XCOMM define I18N/#define I18N/' ${WRKSRC}/Imakefile
.endif

.include <bsd.port.mk>
