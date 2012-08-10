# New ports collection makefile for:	libxfce4menu
# Date created:		7 Oktober 2008
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxfce4menu
PORTVERSION=	4.10.0
PORTREVISION=	2
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DISTNAME=	libxfce4ui-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Widgets library for the Xfce desktop environment

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack gtk20 intltool intlhack desktopfileutils
USE_LDCONFIG=	yes
USE_XFCE=	configenv libutil xfconf
INSTALLS_ICONS=	yes
USE_PKGCONFIG=	build

CONFIGURE_ARGS=	--disable-gtk-doc-html \
		--with-vendor-info=FreeBSD

OPTIONS_DEFINE=		DOCS NLS NOTIFY GLADE
OPTIONS_DEFAULT=	NOTIFY

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

.if ${PORT_OPTIONS:MGLADE}
LIB_DEPENDS+=	gladeui-1.10:${PORTSDIR}/devel/glade3
CONFIGURE_ARGS+=--enable-gladeui
.else
CONFIGURE_ARGS+=--disable-gladeui
.endif

post-patch:
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e 's|docs \\|docs|' \
		-e 's|po||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
