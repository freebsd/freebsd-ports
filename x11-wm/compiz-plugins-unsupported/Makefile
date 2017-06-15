# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compiz-plugins-unsupported
PORTVERSION=	0.8.8
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Plugins for Compiz Composite Window Manager

LIB_DEPENDS=	libcairo.so:graphics/cairo
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/bcop.pc:devel/compiz-bcop \
		${LOCALBASE}/libdata/pkgconfig/compiz-text.pc:x11-wm/compiz-plugins-main

RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_GL=		yes
USES=	pathfix gettext gmake libtool:keepla pkgconfig tar:bzip2
USE_GNOME=	gconf2 intltool
USE_XORG=	glproto
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

.include <bsd.port.mk>
