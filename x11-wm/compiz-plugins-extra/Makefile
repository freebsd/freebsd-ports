# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compiz-plugins-extra
PORTVERSION=	0.8.8
PORTREVISION=	8
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	samy.mahmoudi@gmail.com
COMMENT=	Plugins for Compiz Composite Window Manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libnotify.so:devel/libnotify \
		libstartup-notification-1.so:x11/startup-notification
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/bcop.pc:devel/compiz-bcop \
		${LOCALBASE}/libdata/pkgconfig/compiz-text.pc:x11-wm/compiz-plugins-main
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gettext-runtime gettext-tools gmake gl gnome libtool:keepla \
		pathfix pkgconfig tar:bzip2 xorg
USE_GL=		glu
USE_CSTD=	gnu89
USE_GNOME=	gconf2 gdkpixbuf2 intltool libxslt
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama xorgproto xrandr xrender
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-schemas
GNU_CONFIGURE=	yes
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

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'	\
		${WRKSRC}/src/group/group-internal.h	\

.include <bsd.port.mk>
