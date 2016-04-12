# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	xfce4-desktop
PORTVERSION=	4.12.3
CATEGORIES=	x11-wm xfce
MASTER_SITES=	XFCE/src/xfce/xfdesktop/${PORTVERSION:R}/
DISTNAME=	xfdesktop-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's desktop manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libnotify.so:devel/libnotify

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	glib20 gtk20 intltool intlhack libwnck
USE_XFCE=	garcon
USES=	gettext-tools gmake pkgconfig tar:bzip2 xfce
USE_XORG=	x11 sm
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS+=--enable-gio-unix \
	--enable-notifications

OPTIONS_DEFINE=		NLS THUNAR
OPTIONS_DEFAULT=	THUNAR
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
THUNAR_USE=	xfce=thunar
THUNAR_CONFIGURE_ENABLE=	thunarx
THUNAR_CONFIGURE_WITH=	file-manager-fallback=Thunar
THUNAR_USE_OFF=	xfce=libexo
THUNAR_DESC=	Thunar file manager support
OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

post-patch:
.if !${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|po ||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
