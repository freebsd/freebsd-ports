# New ports collection makefile for:   kdelibs
# Version required:    Beta1
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.5 1997/11/27 00:25:46 se Exp $
#

DISTNAME=	kdelibs-Beta3-1
PKGNAME=	kdelibs-3.1b
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/stable/Beta3/distribution/tgz/source/ \
 		ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.KDE/stable/Beta3/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta3/distribution/tgz/source/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.3[0-9]:${PORTSDIR}/x11/qt \
		jpeg\\.[67]\\.:${PORTSDIR}/graphics/jpeg
#		gif\\.[23]\\.:${PORTSDIR}/graphics/giflib \

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--x-inc=$(X11BASE)/include -I$(PREFIX)/include" \
		"--x-lib=$(X11BASE)/lib -L$(PREFIX)/lib"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)"

WRKSRC=		${WRKDIR}/kdelibs

.include <bsd.port.mk>
