# New ports collection makefile for:	compiz-plugins-main
# Date created:				2007-08-15
# Whom:					Robert Noland <rnoland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	compiz-plugins-main
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	Plugins for Compiz Composite Window Manager

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		pangocairo-1.0:${PORTSDIR}/x11-toolkits/pango
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/bcop.pc:${PORTSDIR}/devel/compiz-bcop
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GL=		yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intltool
USE_XORG=	glproto
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15

GCONF_SCHEMAS=	compiz-animation.schemas \
		compiz-colorfilter.schemas \
		compiz-expo.schemas \
		compiz-ezoom.schemas \
		compiz-imgjpeg.schemas \
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
		compiz-vpswitch.schemas \
		compiz-shift.schemas

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-schemas

.include <bsd.port.mk>
