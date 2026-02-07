PORTNAME=	compiz-plugins-main
DISTVERSION=	0.8.8
PORTREVISION=	13
CATEGORIES=	x11-wm
MASTER_SITES=	https://codeberg.org/BSDforge/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Plugins for Compiz Composite Window Manager
WWW=		https://codeberg.org/BSDforge/${PORTNAME}/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${MY_DEPENDS}
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libharfbuzz.so:print/harfbuzz \
		libpangocairo-1.0.so:x11-toolkits/pango \
		libstartup-notification-1.so:x11/startup-notification
MY_DEPENDS=	${LOCALBASE}/share/pkgconfig/bcop.pc:devel/compiz-bcop \
		${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz
RUN_DEPENDS=	${MY_DEPENDS}

USES=		gettext-tools gl gmake gnome jpeg libtool:keepla localbase:ldflags pathfix \
		pkgconfig xorg
USE_CSTD=	gnu89
USE_GL=		glu
USE_GNOME=	glib20 intltool libxslt
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama xorgproto \
		xrandr xrender

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-schemas

INSTALL_TARGET=	install-strip

# Fix build with clang11
CFLAGS+=	-fcommon

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
