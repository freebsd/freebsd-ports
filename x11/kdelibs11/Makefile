# New ports collection makefile for:   kdelibs
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kdelibs
PORTVERSION= 	1.1.2.1
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1.2/distribution/tar/generic/source/bz2
DISTNAME=	kdelibs-1.1.2

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

LIBVER=		3
PLIST_SUB+=	LIBVER="${LIBVER}"
MAKE_ENV+=	SOMAJOR="${LIBVER}" SOMINOR="0"

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT=		yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=
CONFIGURE_ARGS=	--enable-shared --x-includes="$(X11BASE)/include" \
		--x-libraries="$(X11BASE)/lib" --disable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${PREFIX}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

# generate KDE style mtree
MTREE_CMD=	${CAT} ${MTREE_FILE} ${FILESDIR}/kde.dist | /usr/sbin/mtree
MTREE_ARGS=	-U -d -e -p

pre-install:
.for applink in Applications Development Games Graphics Internet Multimedia \
		Network Settings System Utilities
	@${MKDIR} ${PREFIX}/share/applnk/${applink}
.endfor
.for lang in cs da de el es fi fr hu it ja nl pl pt ru sv zh_CN.GB2312
	@${MKDIR} ${PREFIX}/share/doc/HTML/${lang}
.endfor
.for mimelnk in application audio image inode text video
	@${MKDIR} ${PREFIX}/share/mimelnk/${mimelnk}
.endfor
	@${MKDIR} ${PREFIX}/share/icons/large
	@${MKDIR} ${PREFIX}/share/icons/mini
	@${MKDIR} ${PREFIX}/share/sounds
	@${MKDIR} ${PREFIX}/share/wallpapers

.include <bsd.port.mk>
