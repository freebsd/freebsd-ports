# New ports collection makefile for:	xfce4-panel
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-panel
PORTVERSION=	4.10.0
PORTREVISION=	2
CATEGORIES=	x11-wm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's panel

LIB_DEPENDS=	wnck-1.22:${PORTSDIR}/x11-toolkits/libwnck \
		cairo.2:${PORTSDIR}/graphics/cairo \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 gtk20 intltool intlhack desktopfileutils
USE_LDCONFIG=	yes
USE_PERL5=	yes
USE_XFCE=	configenv garcon libexo libmenu libutil xfconf
USE_XORG=	x11 sm
USE_PKGCONFIG=	build

CONFIGURE_ARGS+=--enable-gio-unix \
		--disable-gtk-doc-html

OPTIONS_DEFINE=		NLS DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.endif

post-patch:
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e 's|	icons \\|	icons|' \
	    -e 's|	po||' ${WRKSRC}/Makefile.in
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
