# New ports collection makefile for:   kdebase
# Version required:    1.0
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.26 1999/01/21 08:15:38 asami Exp $
#

DISTNAME=	kdebase
PKGNAME=	kdebase-1.1a1
CATEGORIES=	misc kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1pre1/distribution/tar/generic/source
EXTRACT_SUFX=	-1.1-alpha1.src.tar.bz2

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	gif.3:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.2:${PORTSDIR}/x11/kdelibs11 \
		Xpm.4:${PORTSDIR}/graphics/xpm

USE_BZIP2=	yes
USE_QT=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--with-extra-includes=$(PREFIX)/include/giflib"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"
MAKE_ENV=	RM=${RM}

.include <bsd.port.mk>
