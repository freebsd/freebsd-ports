# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	libxfce4util
PORTVERSION=	4.10.1
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Extension library for the Xfce desktop environment

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 intltool intlhack
USE_LDCONFIG=	yes
USE_XFCE=	configenv
USES=		gmake pathfix perl5 pkgconfig

OPTIONS_DEFINE=		NLS DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
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

.include <bsd.port.mk>
