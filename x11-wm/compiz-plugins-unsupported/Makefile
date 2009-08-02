# New ports collection makefile for:	compiz-plugins-unsupported
# Date created:				2007-08-17
# Whom:					Robert Noland <rnoland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	compiz-plugins-unsupported
PORTVERSION=	0.8.2
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	Plugins for Compiz Composite Window Manager

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/bcop.pc:${PORTSDIR}/devel/compiz-bcop \
		${LOCALBASE}/libdata/pkgconfig/compiz-text.pc:${PORTSDIR}/x11-wm/compiz-plugins-main

RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GL=		yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intltool
USE_XORG=	glproto
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22

GCONF_SCHEMAS=	compiz-atlantis.schemas \
		compiz-cubemodel.schemas \
		compiz-elements.schemas \
		compiz-fakeargb.schemas \
		compiz-mswitch.schemas \
		compiz-snow.schemas \
		compiz-tile.schemas

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-schemas

.include <bsd.port.mk>
