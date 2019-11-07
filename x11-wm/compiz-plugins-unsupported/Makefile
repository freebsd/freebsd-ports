# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compiz-plugins-unsupported
PORTVERSION=	0.8.8
PORTREVISION=	6
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Plugins for Compiz Composite Window Manager

BROKEN=		unfetchable

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libstartup-notification-1.so:x11/startup-notification
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/bcop.pc:devel/compiz-bcop \
		${LOCALBASE}/libdata/pkgconfig/compiz-text.pc:x11-wm/compiz-plugins-main

RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gl gmake gnome libtool:keepla pathfix pkgconfig tar:bzip2 xorg
USE_GL=		yes
USE_GNOME=	gconf2 intltool libxslt
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama xorgproto xrandr
USE_LDCONFIG=	yes

GCONF_SCHEMAS=	compiz-atlantis.schemas \
		compiz-cubemodel.schemas \
		compiz-elements.schemas \
		compiz-fakeargb.schemas \
		compiz-mswitch.schemas \
		compiz-snow.schemas \
		compiz-tile.schemas

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-schemas

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime gettext-tools

.include <bsd.port.mk>
