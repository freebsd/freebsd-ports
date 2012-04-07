# New ports collection makefile for:	metalock
# Date created:		21 March 2012
# Whom:			Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$
#

PORTNAME=	metalock
PORTVERSION=	0.8.0
CATEGORIES=	x11
MASTER_SITES=	BERLIOS GOOGLE_CODE
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}_theme-Blue_Marble-1.3${EXTRACT_SUFX}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Enhanced X11 screen locker

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/LICENSE

FETCH_ARGS=	"-Fpr"
USE_BZIP2=	yes
USE_XORG=	x11 xt xproto xext xpm

OPTIONS=	IMLIB2 "Use Imlib2" on  \
		XFT "Use Xft Fonts"	on  \
		ULTRAGETOPT "Use Ultragetopt" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_ULTRAGETOPT)
LIB_DEPENDS+=	ultragetopt.0:${PORTSDIR}/devel/ultragetopt
USE_ULTRAGETOPT=	yes
.else
USE_ULTRAGETOPT=	no
.endif

.if !defined(WITHOUT_IMLIB2)
USE_EFL=	imlib2
USE_IMLIB2=	yes
.else
USE_IMLIB2=	no
.endif

.if !defined(WITHOUT_XFT)
USE_XORG+=	xft
USE_XFT=	yes
.else
USE_XFT=	no
.endif

MAKE_ARGS=	PREFIX="${LOCALBASE}" DEST_PREFIX="${PREFIX}" CC="${CC}" \
		USE_XFT="${USE_XFT}" USE_ULTRAGETOPT="${USE_ULTRAGETOPT}" \
		USE_IMLIB2="${USE_IMLIB2}"

WRKSRC=		${WRKDIR}/${DISTNAME}/src

post-extract:
	${MKDIR} ${WRKDIR}/${DISTNAME}/themes
	${CP} -pR ${WRKDIR}/Blue_Marble ${WRKDIR}/${DISTNAME}/themes/

.include <bsd.port.mk>
