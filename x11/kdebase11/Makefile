# New ports collection makefile for:   kdebase
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kdebase
PORTVERSION= 	1.1.2
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1.2/distribution/tar/generic/source/bz2

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		intl.1:${PORTSDIR}/devel/gettext

USE_XLIB=	yes
USE_BZIP2=	yes
USE_QT=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xdmdir=${X11BASE}/lib/X11/xdm
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS) -DHAVE_GETUSERSHELL -DTIME_WITH_SYS_TIME" \
		INSTALL_SCRIPT="install -c -m 555" PATH="${PATH}:${X11BASE}/bin"
USE_GMAKE=	yes
MAKE_ENV=	RM=${RM}
CFLAGS+=	"-I$(PREFIX)/include"

post-install:
	@${ECHO}
	@${ECHO_MSG} "Due to the potential security hole represented by the KDE"
	@${ECHO_MSG} "screensavers, you will have to set them setuid yourself."
	@${ECHO_MSG} "In order to do this, run:"
	@${ECHO_MSG} "		# chmod 4755 ${PREFIX}/bin/*.kss"
	@${ECHO}

.include <bsd.port.mk>
