# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yad
PORTVERSION=	0.35.0
CATEGORIES=	x11 gnome
MASTER_SITES=	SF/${PORTNAME}-dialog/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Display GNOME dialogs from the command line

LICENSE=	GPLv3

USES=		gmake pkgconfig tar:xz
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
NLS_USES=	gettext
GTK2_CONFIGURE_ON=	--with-gtk=gtk2
GTK2_USE=		GNOME=gtk20,intltool
GTK3_CONFIGURE_ON=	--with-gtk=gtk3
GTK3_USE=		GNOME=gtk30,intltool
ICONBROWSER_CONFIGURE_ENABLE=	icon-browser

.include <bsd.port.options.mk>

post-configure:
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e '/^SUBDIRS =/ s/ po//' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
