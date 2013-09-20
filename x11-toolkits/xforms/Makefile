# Created by: gena
# $FreeBSD$

PORTNAME=	xforms
DISTVERSION=	1.0.93sp1
PORTEPOCH=	1
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A graphical user interface toolkit for X Window System

LICENSE=	LGPL21

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_XORG=	xpm
USE_GL=		gl
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

MAN1=		fdesign.1 fd2ps.1
MAN5=		xforms.5

#
# This patchset does not apply to this version
#
.if defined(WITH_I18N)
PKGNAMESUFFIX=	-i18n
BROKEN=		Does not work with latest xforms version
#PATCH_SITES=	ftp://cellular.phys.pusan.ac.kr/CJK-LyX/xforms/ \
#		http://www.otaru-uc.ac.jp/~yokota/comp/
#PATCHFILES=	xforms-1.0-i18n_7.patch
#PATCH_DIST_STRIP=	-p1
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not compile on ia64
.endif

.include <bsd.port.post.mk>
