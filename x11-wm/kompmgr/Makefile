# New ports collection makefile for:	mpeglib_artsplug
# Date created:				July 09 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kompmgr
PORTVERSION=	${KDE_VERSION}
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

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/kdebase-${PORTVERSION}
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS+=--without-java

PLIST_FILES=	bin/kompmgr

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=	Requires the composite extension, which is unavailable with XFree86
.endif

pre-configure:
	${CP} ${FILESDIR}/configure ${WRKSRC}/

do-build:
	cd ${WRKSRC}/kwin/kompmgr && ${GMAKE}

do-install:
	cd ${WRKSRC}/kwin/kompmgr && ${GMAKE} install

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
