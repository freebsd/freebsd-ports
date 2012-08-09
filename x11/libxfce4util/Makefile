# New ports collection makefile for:	libxfce4util
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	libxfce4util
PORTVERSION=	4.10.0
PORTREVISION=	1
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Extension library for the Xfce desktop environment

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack intltool intlhack
USE_PERL5=	yes
USE_LDCONFIG=	yes
USE_XFCE=	configenv
USE_PKGCONFIG=	build

CONFIGURE_ARGS+=--disable-gtk-doc-html

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

.if empty(PORT_OPTIONS:MNLS)
post-patch:
	@${REINPLACE_CMD} -e 's|po||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
