# New ports collection makefile for:	mpeglib_artsplug
# Date created:				July 09 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kompmgr
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	3
CATEGORIES=	x11-wm kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
PKGNAMEPREFIX=	kdebase-
DISTNAME=	kdebase-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Utility needed to enable XComposite support in KDE

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}
USE_XORG=	x11 xdamage xrender xcomposite xfixes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/kdebase-${PORTVERSION}

PLIST_FILES=	bin/kompmgr

BROKEN=		does not build

.include <bsd.port.pre.mk>

do-build:
	cd ${WRKSRC}/kwin/kompmgr && \
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib -lX11 -lXdamage\
	-lXfixes -lXrender -lXcomposite -lm -o kompmgr kompmgr.c

do-install:
	cd ${WRKSRC}/kwin/kompmgr && ${INSTALL_PROGRAM} kompmgr\
	${PREFIX}/bin/kompmgr

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
