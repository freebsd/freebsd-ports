PORTNAME=	compiz-plugins-extra
PORTVERSION=	0.8.8
PORTREVISION=	13
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	samy.mahmoudi@gmail.com
COMMENT=	Plugins for Compiz Composite Window Manager
WWW=		https://gitlab.com/compiz/compiz-plugins-extra

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libnotify.so:devel/libnotify \
		libstartup-notification-1.so:x11/startup-notification
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/bcop.pc:devel/compiz-bcop \
		${LOCALBASE}/libdata/pkgconfig/compiz-text.pc:x11-wm/compiz-plugins-main
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gettext-tools gmake gl gnome libtool:keepla localbase:ldflags \
		pathfix pkgconfig tar:bzip2 xorg
USE_GL=		glu
USE_CSTD=	gnu89
USE_GNOME=	gdkpixbuf intltool libxslt
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama xorgproto xrandr xrender
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-schemas
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'	\
		${WRKSRC}/src/group/group-internal.h	\

.include <bsd.port.mk>
