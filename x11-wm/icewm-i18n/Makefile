# New ports collection makefile for:	icewm-i18n
# Date created:		2 Oct 1999
# Whom:			Yoichi ASAI <yatt@msc.biglobe.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	icewm-i18n
PORTVERSION=	1.0.3
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/icewm/
MASTER_SITE_SUBDIR=	icewm
DISTNAME=	icewm-${PORTVERSION}
EXTRACT_SUFX=	.src.tar.gz

PATCH_SITES=	http://www.gnome.gr.jp/~yatt/dist/
PATCHFILES=	icewm-1.0.3-nls.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	yatt@msc.biglobe.ne.jp

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		intl.1:${PORTSDIR}/devel/gettext

.if defined(WITH_GNOME)
LIB_DEPENDS+=	gnome.3:${PORTSDIR}/x11/gnomelibs
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

CONFIGURE_ARGS=	--enable-i18n --enable-nls
CONFIGURE_ENV=	CXXFLAGS=-I${LOCALBASE}/include \
		LIBS="-L${LOCALBASE}/lib -lxpg4"
INSTALL_TARGET=	install install-po

.if defined(WITH_GNOME)
CONFIGURE_ARGS+=	--with-imlib --with-gnome-menus
.else
CONFIGURE_ARGS+=	--without-imlib --without-gnome-menus
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/bsd-daemon.xpm \
	${PREFIX}/share/icewm/taskbar

.include <bsd.port.mk>
