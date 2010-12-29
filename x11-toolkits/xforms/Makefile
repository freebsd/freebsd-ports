# New ports collection makefile for:	xforms
# Date created:		28 March 1997
# Whom:			gena
#
# $FreeBSD$
#

PORTNAME=	xforms
PORTVERSION=	1.0
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	${MASTER_SITE_SAVANNAH:S/$/:savannah/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	${PORTNAME}/stable.pkg/${PORTVERSION}/:savannah \
			mikeh/:local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:savannah,local

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	A graphical user interface toolkit for X Window System

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_XORG=	xpm
USE_GL=		gl
USE_IMAKE=	yes
USE_LDCONFIG=	yes

MAN1=		fdesign.1 fd2ps.1

.if defined(WITH_I18N)
PKGNAMESUFFIX=	-i18n
PATCH_SITES=	ftp://cellular.phys.pusan.ac.kr/CJK-LyX/xforms/ \
		http://www.otaru-uc.ac.jp/~yokota/comp/
PATCHFILES=	xforms-1.0-i18n_7.patch
PATCH_DIST_STRIP=	-p1
.endif

REINPLACE_ARGS=	-i ""

post-patch:
	${REINPLACE_CMD} -e 's|-O4||' ${WRKSRC}/Imakefile
.if defined(LOCALBASE)
.	if ${LOCALBASE} != "/usr/X11R6"
	${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/image/rgb_db.c
.	endif
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=	does not build
.endif

.if ${ARCH} == "ia64"
BROKEN=		Does not compile on ia64
.endif

.include <bsd.port.post.mk>
