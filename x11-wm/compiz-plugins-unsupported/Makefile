PORTNAME=	compiz-plugins-unsupported
DISTVERSION=	0.8.8
PORTREVISION=	12
CATEGORIES=	x11-wm
MASTER_SITES=	https://codeberg.org/BSDforge/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Plugins for the Compiz Composite Window Manager
WWW=		https://codeberg.org/BSDforge/${PORTNAME}/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${MY_DEPENDS}
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libstartup-notification-1.so:x11/startup-notification
MY_DEPENDS=	${LOCALBASE}/share/pkgconfig/bcop.pc:devel/compiz-bcop \
		${LOCALBASE}/libdata/pkgconfig/compiz-text.pc:x11-wm/compiz-plugins-main \
		${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz
RUN_DEPENDS=	${MY_DEPENDS}

USES=		gettext-tools gmake gnome libtool:keepla localbase:ldflags \
		pathfix pkgconfig xorg
# pet pkgfallout@ till I finish updating Compiz et al;
USE_CSTD=	gnu89
USE_GNOME=	intltool libxslt
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama xorgproto \
		xrandr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-schemas

INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
