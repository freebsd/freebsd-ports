# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-desktop
PORTVERSION=	3.28.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for GNOME 3

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING.LIB

PORTSCOUT=	limitw:1,even

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		xkeyboard-config>=0:x11/xkeyboard-config \
		itstool:textproc/itstool
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		cantarell-fonts>=0:x11-fonts/cantarell-fonts \
		xkeyboard-config>=0:x11/xkeyboard-config

USES=		bison gettext gmake gnome libtool localbase pathfix \
		pkgconfig python:3.4+ tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool introspection:build
USE_XORG=	x11
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gnome-distributor="FreeBSD GNOME Project" \
		--disable-udev
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|xsltproc -o| xsltproc --nonet -o|g' \
		${WRKSRC}/desktop-docs/fdl/Makefile.in \
		${WRKSRC}/desktop-docs/gpl/Makefile.in \
		${WRKSRC}/desktop-docs/lgpl/Makefile.in

.include <bsd.port.mk>
