PORTNAME=	xfce4-desktop
PORTVERSION=	4.18.1
PORTREVISION=	3
CATEGORIES=	x11-wm xfce
MASTER_SITES=	XFCE
DISTNAME=	xfdesktop-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's desktop manager
WWW=		https://www.xfce.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome pkgconfig tar:bzip2 \
		xfce xorg
USE_GNOME=	cairo glib20 gdkpixbuf2 gtk30 intltool libwnck3
USE_XFCE=	garcon libexo xfconf
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--enable-gio-unix \
		--enable-notifications

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=			NLS THUNAR
OPTIONS_DEFAULT=		THUNAR
OPTIONS_SUB=			yes

THUNAR_DESC=			Thunar file manager support

NLS_CONFIGURE_ENABLE=		nls
NLS_USES=			gettext-runtime

THUNAR_CONFIGURE_ENABLE=	thunarx
THUNAR_CONFIGURE_WITH=		file-manager-fallback=Thunar
THUNAR_USE=			xfce=thunar

.include <bsd.port.mk>
