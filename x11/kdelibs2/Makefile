# New ports collection makefile for:   kdelibs
# Version required:    Beta1
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.4 1997/11/05 21:31:52 asami Exp $
#

DISTNAME=	kdelibs-Beta2-1
PKGNAME=	kdelibs-2.1b
CATEGORIES=	x11 kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/stable/Beta2/distribution/tgz/source/ \
 		ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.KDE/stable/Beta2/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta2/distribution/tgz/source/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.3[0-9]:${PORTSDIR}/x11/qt \
		gif\\.[23]\\.:${PORTSDIR}/graphics/giflib \
		jpeg\\.[67]\\.:${PORTSDIR}/graphics/jpeg

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--x-inc=$(X11BASE)/include -I$(PREFIX)/include -I$(PREFIX)/include/giflib" \
		"--x-lib=$(X11BASE)/lib -L$(PREFIX)/lib" \
		"--datadir=$(PREFIX)/share/kde"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)"

WRKSRC=		${WRKDIR}/kdelibs

.include <bsd.port.mk>
