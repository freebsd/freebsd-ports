# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yad
PORTVERSION=	0.24.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Display GNOME dialogs from the command line

USES=		gmake pkgconfig
USE_XZ=		yes
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV+=	DATADIRNAME=share

OPTIONS_DEFINE=	NLS ICONBROWSER
ICONBROWSER_DESC=	Build YAD icon browser
OPTIONS_SUB=	yes

OPTIONS_SINGLE=	GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3

OPTIONS_DEFAULT=	GTK2

NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=	gettext
GTK2_CONFIGURE_ON=	--with-gtk=gtk2
GTK3_CONFIGURE_ON=	--with-gtk=gtk3
ICONBROWSER_CONFIGURE_ENABLE=	icon-browser

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20
.else
USE_GNOME=	gtk30
.endif

post-configure:
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e '/^SUBDIRS =/ s/ po//' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
