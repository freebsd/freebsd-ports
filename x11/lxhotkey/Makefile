PORTNAME=	lxhotkey
PORTVERSION=	0.1.1
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/LXHotkey/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keyboard shortcuts settings
WWW=		https://www.lxde.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfm-extra.so:x11/libfm-extra \
	libfm.so:x11/libfm@gtk2 \
	libfontconfig.so:x11-fonts/fontconfig \
	libfreetype.so:print/freetype2 \
	libunistring.so:devel/libunistring

USES=		gettext-tools gmake gnome pathfix pkgconfig tar:xz xorg
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_GNOME=	glib20 gtk20 intltool cairo gdkpixbuf2
USE_XORG=	x11

CONFIGURE_ARGS=	--with-gtk=2

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lxhotkey/*.so

.include <bsd.port.mk>
