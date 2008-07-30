# New ports collection makefile for:	compiz-fusion-plugins-extra
# Date created:				2007-08-17
# Whom:					Robert Noland <rnoland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	compiz-fusion-plugins-extra
PORTVERSION=	0.6.0
#PORTREVISION=	1
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz-fusion.org/${PORTVERSION}/

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	Plugins for Compiz Composite Window Manager

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/bcop.pc:${PORTSDIR}/devel/compiz-bcop \
		${LOCALBASE}/libdata/pkgconfig/compiz-text.pc:${PORTSDIR}/x11-wm/compiz-fusion-plugins-main
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

GCONF_SCHEMAS=	compiz-addhelper.schemas \
		compiz-bench.schemas \
		compiz-crashhandler.schemas \
		compiz-cubecaps.schemas \
		compiz-cubereflex.schemas \
		compiz-extrawm.schemas \
		compiz-fadedesktop.schemas \
		compiz-firepaint.schemas \
		compiz-gears.schemas \
		compiz-group.schemas \
		compiz-mblur.schemas \
		compiz-reflex.schemas \
		compiz-scalefilter.schemas \
		compiz-showdesktop.schemas \
		compiz-splash.schemas \
		compiz-trailfocus.schemas \
		compiz-widget.schemas

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-schemas

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'	\
		${WRKSRC}/src/group/group-internal.h	\

.include <bsd.port.mk>
