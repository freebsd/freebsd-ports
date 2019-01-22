# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	xfce4-panel
PORTVERSION=	4.12.2
CATEGORIES=	x11-wm xfce
MASTER_SITES=	XFCE/src/xfce/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's panel

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		desktop-file-utils gettext-tools gmake gnome libtool pathfix \
		perl5 pkgconfig tar:bzip2
USE_GNOME=	cairo glib20 gtk20 intlhack intltool libwnck
USE_LDCONFIG=	yes
USE_XFCE=	garcon libexo
USE_XORG=	ice sm x11 xext

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--enable-gio-unix --without-html-dir

PORTSCOUT=	limit:^4\.12\.

OPTIONS_DEFINE=		GTK3 NLS
OPTIONS_DEFAULT=	GTK3
OPTIONS_SUB=		yes

GTK3_CONFIGURE_ENABLE=	gtk3
GTK3_USE=		gnome=gtk30
GTK3_USES_OFF=		xfce
GTK3_USES=		xfce:gtk3

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
