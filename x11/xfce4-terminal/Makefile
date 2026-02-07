PORTNAME=	xfce4-terminal
PORTVERSION=	1.1.5
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Terminal emulator for the X windowing system
WWW=		https://docs.xfce.org/apps/xfce4-terminal/start

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.4/catalog.xml:textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/html/refentry.xsl:textproc/docbook-xsl \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz xfce \
		xorg
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 vte3
USE_XFCE=	libmenu xfconf
USE_XORG=	ice sm x11

MESON_ARGS=	-Dlibutempter=enabled

OPTIONS_DEFINE=		NLS WAYLAND
OPTIONS_DEFAULT=	WAYLAND
OPTIONS_SUB=		yes

NLS_USES=	gettext-runtime

WAYLAND_LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
WAYLAND_MESON_ENABLED=	gtk-layer-shell wayland

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
