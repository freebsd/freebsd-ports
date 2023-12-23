PORTNAME=	xfce4-terminal
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Terminal emulator for the X windowing system
WWW=		https://www.xfce.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		compiler:c11 gettext-tools gmake gnome pkgconfig tar:bzip2 \
		xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool vte3
USE_XFCE=	libmenu xfconf
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-utempter
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
