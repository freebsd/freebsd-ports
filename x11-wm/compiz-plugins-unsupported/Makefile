# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compiz-plugins-unsupported
PORTVERSION=	0.8.4
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugins for Compiz Composite Window Manager

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/bcop.pc:${PORTSDIR}/devel/compiz-bcop \
		${LOCALBASE}/libdata/pkgconfig/compiz-text.pc:${PORTSDIR}/x11-wm/compiz-plugins-main

RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GL=		yes
USE_BZIP2=	yes
USES=        pathfix gettext gmake pkgconfig
USE_GNOME=	intltool
USE_XORG=	glproto
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool

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

NO_STAGE=	yes
.include <bsd.port.mk>
