# New ports collection makefile for:	beryl-plugins
# Date created:				Oct 29 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	beryl-plugins
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.beryl-project.org/${PORTVERSION}/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flz/beryl/

MAINTAINER=	rnoland@2hip.net
COMMENT=	Plugins for Beryl Composite/Window Manager

# XXX - Might depends on graphics/libsvg-cairo instead.
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/beryl.pc:${PORTSDIR}/x11-wm/beryl-core
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GL=		yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 librsvg2
USE_XORG=	glproto
USE_GETTEXT=	yes
USE_LDCONFIG=	yes

DEPRECATED=	No longer supported - Use compiz
EXPIRATION_DATE=	2008-08-02

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	DBUS "Enable dbus support" On

.include <bsd.port.pre.mk>

.if defined(WITH_DBUS)
CONFIGURE_ARGS=	--enable-dbus
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:${PORTSDIR}/devel/dbus
PLIST_SUB=	DBUS=""
.else
CONFIGURE_ARGS=	--disable-dbus
PLIST_SUB=	DBUS="@comment "
.endif

.include <bsd.port.post.mk>
