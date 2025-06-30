PORTNAME=	compiz-plugins-main
PORTVERSION=	0.8.8
PORTREVISION=	12
CATEGORIES=	x11-wm
MASTER_SITES=	https://BSDforge.com/projects/source/x11-wm/compiz-plugins-main/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Plugins for Compiz Composite Window Manager
WWW=		https://gitlab.com/compiz/compiz-plugins-main

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libpangocairo-1.0.so:x11-toolkits/pango \
		libstartup-notification-1.so:x11/startup-notification
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/bcop.pc:devel/compiz-bcop
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gettext-tools gl gmake gnome jpeg libtool:keepla localbase:ldflags pathfix \
		pkgconfig tar:bzip2 xorg
USE_CSTD=	gnu89
USE_GL=		glu
USE_GNOME=	intltool libxslt
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama xorgproto xrandr xrender
USE_LDCONFIG=	yes

# Fix build with clang11
CFLAGS+=	-fcommon

CONFIGURE_ARGS=	--disable-schemas

OPTIONS_DEFINE=		NLS

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
