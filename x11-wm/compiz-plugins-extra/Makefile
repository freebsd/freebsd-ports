# New ports collection makefile for:	compiz-plugins-extra
# Date created:				2007-08-17
# Whom:					Robert Noland <rnoland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	compiz-plugins-extra
PORTVERSION=	0.8.2
PORTREVISION=	1
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

GCONF_SCHEMAS=	compiz-3d.schemas \
		compiz-addhelper.schemas \
		compiz-animationaddon.schemas \
		compiz-bench.schemas \
		compiz-bicubic.schemas \
		compiz-crashhandler.schemas \
		compiz-cubeaddon.schemas \
		compiz-extrawm.schemas \
		compiz-fadedesktop.schemas \
		compiz-firepaint.schemas \
		compiz-gears.schemas \
		compiz-grid.schemas \
		compiz-group.schemas \
		compiz-loginout.schemas \
		compiz-maximumize.schemas \
		compiz-mblur.schemas \
		compiz-notification.schemas \
		compiz-reflex.schemas \
		compiz-scalefilter.schemas \
		compiz-shelf.schemas \
		compiz-showdesktop.schemas \
		compiz-showmouse.schemas \
		compiz-splash.schemas \
		compiz-trailfocus.schemas \
		compiz-wallpaper.schemas \
		compiz-widget.schemas

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-schemas

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'	\
		${WRKSRC}/src/group/group-internal.h	\

.include <bsd.port.mk>
