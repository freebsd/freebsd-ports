# New ports collection makefile for:   kdelibs
# Version required:    1.1.2
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	kdelibs-1.1.2
PKGNAME=	kdelibs-1.1.2.1
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1.2/distribution/tar/generic/source/bz2

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_BZIP2=	yes
USE_QT=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --x-includes="$(X11BASE)/include" \
		--x-libraries="$(X11BASE)/lib" --disable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${PREFIX}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
LIBVER=		3
PLIST_SUB+=	LIBVER="${LIBVER}"
MAKE_ENV+=	SOMAJOR="${LIBVER}" SOMINOR="0"

# generate KDE style mtree
MTREE_CMD=	${CAT} ${MTREE_FILE} ${FILESDIR}/kde.dist | /usr/sbin/mtree
MTREE_ARGS=	-U -d -e -p

post-install:
.for LIB in jscript kab kdecore kdeui kfile kfm khtmlw kimgio kspell mediatool
	@${LN} -sf ${PREFIX}/lib/lib${LIB}.so.${LIBVER} ${PREFIX}/lib/lib${LIB}.so
.endfor

.include <bsd.port.mk>
