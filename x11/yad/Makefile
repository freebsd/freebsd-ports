# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yad
PORTVERSION=	0.38.1
CATEGORIES=	x11 gnome
MASTER_SITES=	SF/${PORTNAME}-dialog/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Display GNOME dialogs from the command line

LICENSE=	GPLv3

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext gmake pkgconfig tar:xz
USE_GNOME=	cairo intltool
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV+=	DATADIRNAME=share
CONFIGURE_ARGS+=	--disable-html

OPTIONS_DEFINE=	NLS ICONBROWSER
ICONBROWSER_DESC=	Build YAD icon browser
OPTIONS_SUB=	yes

OPTIONS_SINGLE=	GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3

OPTIONS_DEFAULT=	GTK2

NLS_CONFIGURE_OFF=	--disable-nls
GTK2_CONFIGURE_ON=	--with-gtk=gtk2
GTK2_USE=		GNOME=gtk20
GTK3_CONFIGURE_ON=	--with-gtk=gtk3
GTK3_USE=		GNOME=gtk30
ICONBROWSER_CONFIGURE_ENABLE=	icon-browser

.include <bsd.port.options.mk>

post-configure:
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e '/^SUBDIRS =/ s/ po//' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
