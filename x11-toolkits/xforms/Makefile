# New ports collection makefile for:	xforms
# Date created:		28 March 1997
# Whom:			gena
#
# $FreeBSD$
#

PORTNAME=	xforms
PORTVERSION=	1.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	${PORTNAME}/stable.pkg/${PORTVERSION} \
			mikeh
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

MAINTAINER=	mikeh@FreeBSD.ORG
COMMENT=	A graphical user interface toolkit for X Window System

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_XPM=	yes
USE_IMAKE=	yes
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes

MAN1=		fdesign.1 fd2ps.1

post-patch:
	${REINPLACE_CMD} -e 's|-O4||' ${WRKSRC}/Imakefile
.if defined(X11BASE)
.	if ${X11BASE} != "/usr/X11R6"
	${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' \
		${WRKSRC}/image/rgb_db.c
.	endif
.endif

.include <bsd.port.mk>
