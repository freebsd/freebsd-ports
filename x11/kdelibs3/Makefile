# New ports collection makefile for:   kdelibs
# Version required:    Beta1
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.10 1998/04/25 07:29:43 se Exp $
#

DISTNAME=	kdelibs-beta4-1
PKGNAME=	kdelibs-4.1b
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/Beta4/distribution/tgz/source
EXTRACT_SUFX=	.src.tar.bz2

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2 \
		moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.3[0-9]:${PORTSDIR}/x11/qt \
		gif\\.[23]\\.:${PORTSDIR}/graphics/giflib \
		jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg

EXTRACT_CMD=	bzip2
EXTRACT_BEFORE_ARGS= -cd
EXTRACT_AFTER_ARGS= | tar -xf -

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--x-inc=$(X11BASE)/include" \
		"--x-lib=$(X11BASE)/lib"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)"

WRKSRC=		${WRKDIR}/kdelibs

.include <bsd.port.mk>
