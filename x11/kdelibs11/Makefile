# New ports collection makefile for:   kdelibs
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kdelibs
PORTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= Attic/old/1.1.2/distribution/tar/generic/source/bz2
DISTNAME=	kdelibs-1.1.2

PATCH_SITES=	ftp://ftp.kde.gr.jp/pub/kde/stable/latest/distribution/tar/generic/jp-patch/
PATCHFILES=	kdelibs-ja.19990903.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

LIBVER=		3
PLIST_SUB+=	LIBVER="${LIBVER}"
MAKE_ENV+=	SOMAJOR="${LIBVER}" SOMINOR="0"
NO_LATEST_LINK=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	1
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=
CONFIGURE_ARGS=	--enable-shared --x-includes="$(X11BASE)/include" \
		--x-libraries="$(X11BASE)/lib" --disable-static \
		--with-qt-includes=${QTDIR}/include/X11/qt
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${PREFIX}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		QTDIR=${QTDIR}

# generate KDE style mtree
MTREE_CMD=	${CAT} ${MTREE_FILE} ${FILESDIR}/kde.dist | /usr/sbin/mtree
MTREE_ARGS=	-U -d -e -p

.include <bsd.port.mk>
