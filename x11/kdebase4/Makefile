# New ports collection makefile for:   kdebase
# Version required:    1.0
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	kdebase-1.1.1
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1.1/distribution/tar/generic/source/bz2

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	gif.5:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.2:${PORTSDIR}/x11/kdelibs11 \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		intl.1:${PORTSDIR}/devel/gettext

USE_BZIP2=	yes
USE_QT=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS) -DHAVE_GETUSERSHELL -DTIME_WITH_SYS_TIME" \
		INSTALL_SCRIPT="install -c -m 555"
USE_GMAKE=	yes
MAKE_ENV=	RM=${RM}
CFLAGS+=	"-I$(PREFIX)/include"

.include <bsd.port.mk>
