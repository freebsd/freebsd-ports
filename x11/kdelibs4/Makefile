# New ports collection makefile for:   kdelibs
# Version required:    Beta1
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.8 1998/03/06 19:52:23 se Exp $
#

DISTNAME=	kdelibs-Beta3-1
PKGNAME=	kdelibs-3.1b
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/Beta3/distribution/tgz/source 
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.3[0-9]:${PORTSDIR}/x11/qt \
		gif\\.[23]\\.:${PORTSDIR}/graphics/giflib \
		jpeg\\.8\\.:${PORTSDIR}/graphics/jpeg

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--x-inc=$(X11BASE)/include" \
		"--x-lib=$(X11BASE)/lib"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)"

WRKSRC=		${WRKDIR}/kdelibs

.include <bsd.port.mk>
