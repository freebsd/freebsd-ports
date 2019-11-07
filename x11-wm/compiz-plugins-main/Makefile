# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compiz-plugins-main
PORTVERSION=	0.8.8
PORTREVISION=	6
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Plugins for Compiz Composite Window Manager

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
USES=		gl gmake gnome jpeg libtool:keepla pathfix pkgconfig tar:bzip2 \
		xorg
USE_CSTD=	gnu89
USE_GL=		yes
USE_GNOME=	gconf2 intltool libxslt
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama xorgproto xrandr xrender
USE_LDCONFIG=	yes

GCONF_SCHEMAS=	compiz-animation.schemas \
		compiz-colorfilter.schemas \
		compiz-expo.schemas \
		compiz-ezoom.schemas \
		compiz-imgjpeg.schemas \
		compiz-kdecompat.schemas \
		compiz-mag.schemas \
		compiz-mousepoll.schemas \
		compiz-neg.schemas \
		compiz-opacify.schemas \
		compiz-put.schemas \
		compiz-resizeinfo.schemas \
		compiz-ring.schemas \
		compiz-staticswitcher.schemas \
		compiz-session.schemas \
		compiz-snap.schemas \
		compiz-text.schemas \
		compiz-thumbnail.schemas \
		compiz-wall.schemas \
		compiz-winrules.schemas \
		compiz-workarounds.schemas \
		compiz-scaleaddon.schemas \
		compiz-titleinfo.schemas \
		compiz-vpswitch.schemas \
		compiz-shift.schemas

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-schemas

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime gettext-tools

.include <bsd.port.mk>
