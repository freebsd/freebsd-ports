# Created by: Matt Lancereau
# $FreeBSD$

PORTNAME=	xfce4-terminal
PORTVERSION=	0.8.9.1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Terminal emulator for the X windowing system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gettext-tools gmake gnome pkgconfig tar:bzip2 \
		xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool libxml2 vte3
USE_XFCE=	libmenu xfconf
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-message
CONFIGURE_ARGS=	--without-gnome-default-appsdir

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
