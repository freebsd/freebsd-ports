# New ports collection makefile for:   kdebase
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kdebase
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= Attic/old/1.1.2/distribution/tar/generic/source/bz2
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		intl.1:${PORTSDIR}/devel/gettext

NO_LATEST_LINK=	yes
USE_XLIB=	yes
USE_XPM=	yes
USE_BZIP2=	yes
USE_QT_VER=	1
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt-includes=${QTDIR}/include/X11/qt \
		--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib \
		--with-xdmdir=${X11BASE}/lib/X11/xdm
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS) -DHAVE_GETUSERSHELL -DTIME_WITH_SYS_TIME" \
		INSTALL_SCRIPT="install -c -m 555" PATH="${PATH}:${X11BASE}/bin" \
		RUN_KAPPFINDER="no" \
		QTDIR=${QTDIR}
MAKE_ENV=	RM=${RM}
CFLAGS+=	"-I$(PREFIX)/include"

pre-patch:
	@${CP} ${FILESDIR}/ja.kimap ${WRKSRC}/kikbd/maps

post-install:
	${INSTALL_DATA} ${FILESDIR}/kwmrc ${PREFIX}/share/config
	@${ECHO}
	@${ECHO_MSG} "Due to the potential security hole represented by the KDE"
	@${ECHO_MSG} "screensavers, you will have to set them setuid yourself."
	@${ECHO_MSG} "In order to do this, run:"
	@${ECHO_MSG} "		# chmod 4755 ${PREFIX}/bin/*.kss"
	@${ECHO}

.include <bsd.port.mk>
