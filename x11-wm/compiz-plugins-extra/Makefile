# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compiz-plugins-extra
PORTVERSION=	0.8.8
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Plugins for Compiz Composite Window Manager

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libnotify.so:devel/libnotify
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/bcop.pc:devel/compiz-bcop \
		${LOCALBASE}/libdata/pkgconfig/compiz-text.pc:x11-wm/compiz-plugins-main
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GL=		yes
USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	gconf2 intltool
USE_XORG=	glproto
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

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

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-schemas

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'	\
		${WRKSRC}/src/group/group-internal.h	\

.include <bsd.port.mk>
