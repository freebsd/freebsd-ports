PORTNAME=	tilix
PORTVERSION=	1.9.6
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Tiling terminal emulator using GTK 3
WWW=		https://gnunn1.github.io/tilix-web/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		po4a-translate:textproc/po4a \
		${LOCALBASE}/libdata/pkgconfig/undead.pc:devel/undead \
		${LOCALBASE}/libdata/pkgconfig/vted-3.pc:x11-toolkits/gtkd
LIB_DEPENDS=	libdruntime-ldc-shared.so:lang/ldc \
		libharfbuzz.so:print/harfbuzz \
		libsecret-1.so:security/libsecret \
		libunwind.so:devel/libunwind

USES=		desktop-file-utils gettext gnome meson pkgconfig shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	gnunn1
USE_GNOME=	cairo gdkpixbuf librsvg2 vte3
USE_XORG=	x11
GLIB_SCHEMAS=	com.gexperts.Tilix.gschema.xml
SHEBANG_FILES=	data/scripts/tilix_int.sh

.include <bsd.port.mk>
