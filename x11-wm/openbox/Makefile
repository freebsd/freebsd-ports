# Created by: trevor
# $FreeBSD$

PORTNAME=	openbox
PORTVERSION=	3.6
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	http://openbox.org/dist/openbox/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Small, fast, standards compliant, extensible window manager

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix python:run pkgconfig shebangfix
USE_GNOME=	cairo glib20 libxml2
USE_XORG=	ice sm x11 xcursor xext xft xinerama xrandr \
		xrender xau
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	data/autostart/openbox-xdg-autostart
ETCDIR=		${PREFIX}/etc/xdg/${PORTNAME}

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lXext

PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	NLS IMLIB PANGO SVG NOTIFY PATCHES
OPTIONS_DEFAULT=	IMLIB PANGO NOTIFY SVG
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls

PANGO_USE=		GNOME=pango
PANG_CONFIGURE_OFF=	--disable-pango

NOTIFY_LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification
NOTIFY_CONFIGURE_OFF=	--disable-startup-notification

IMLIB_CONFIGURE_ENABLE=	imlib2
IMLIB_LIB_DEPENDS=	libImlib2.so:graphics/imlib2

SVG_USE=	GNOME=librsvg2
SVG_CONFIGURE_ENABLE=	librsvg

PATCHES_DESC=		Enable 3rd party patches (such as rounded corners)
PATCHES_EXTRA_PATCHES=	${PATCHDIR}/openbox-3.5.0-title-matching.patch:-p1 \
			${PATCHDIR}/openbox-3.5.0-which-2.20.patch:-p1 \
			${PATCHDIR}/openbox-3.6.2-fix-out-of-bounds.patch:-p1 \
			${PATCHDIR}/openbox-3.6.2-rounded-corners.patch:-p1

post-configure:
	@${CHMOD} +x ${WRKSRC}/install-sh

post-install:
.for config_file in autostart environment menu.xml rc.xml
	@${MV} ${STAGEDIR}${ETCDIR}/${config_file} \
		${STAGEDIR}${ETCDIR}/${config_file}.sample
.endfor

.include <bsd.port.mk>
