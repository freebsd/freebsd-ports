# New ports collection makefile for:   kdebase
# Version required:    1.1.2
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	kdebase-1.1.2
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1.2/distribution/tar/generic/source/bz2

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		intl.1:${PORTSDIR}/devel/gettext

USE_XLIB=	yes
USE_BZIP2=	yes
USE_QT=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--with-xdmdir=${X11BASE}/lib/X11/xdm"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS) -DHAVE_GETUSERSHELL -DTIME_WITH_SYS_TIME" \
		INSTALL_SCRIPT="install -c -m 555" \
		PATH="${PATH}:${X11BASE}/bin"
USE_GMAKE=	yes
MAKE_ENV=	RM=${RM}
CFLAGS+=	"-I$(PREFIX)/include"

KSSES=	kattraction.kss kbanner.kss kbat.kss kblankscrn.kss \
	kblob.kss kbouboule.kss kbsod.kss kflame.kss kforest.kss \
	khop.kss klaser.kss klines.kss klissie.kss kmatrix.kss \
	kmorph3d.kss kpipes.kss kpolygon.kss kpyro.kss krock.kss \
	kscience.kss kslidescreen.kss kslip.kss kspace.kss kswarm.kss

post-install:
.for KSS in $(KSSES)
	$(CHMOD) 4555 $(PREFIX)/bin/$(KSS)
.endfor

.include <bsd.port.mk>
