# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yad
PORTVERSION=	6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	x11 gnome

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Display GNOME dialogs from the command line

LICENSE=	GPLv3

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/lib/X11/rgb.txt:x11/rgb

USES=		autoreconf gettext gnome gmake pkgconfig

USE_GNOME=	cairo gtk30 intltool
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV+=	DATADIRNAME=share
CONFIGURE_ARGS+=	--with-rgb=${LOCALBASE}/lib/X11/rgb.txt
GLIB_SCHEMAS=	yad.gschema.xml

USE_GITHUB=	yes
GH_ACCOUNT=	v1cont

OPTIONS_DEFINE=	HTML ICONBROWSER NLS PFD GTKSOURCEVIEW SPELL
HTML_DESC=		Build with HTML widget
ICONBROWSER_DESC=	Build YAD icon browser
PFD_DESC=		Build PFD fontnames transformation utility
GTKSOURCEVIEW_DESC=	Build with GtkSourceView support
SPELL_DESC=		Build with Spell check support
OPTIONS_DEFAULT=	SPELL
OPTIONS_SUB=	yes

HTML_CONFIGURE_ENABLE=	html
HTML_LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
			libsoup-2.4.so:devel/libsoup \
			libjavascriptcoregtk-4.0.so:www/webkit2-gtk3

ICONBROWSER_CONFIGURE_ENABLE=	icon-browser

PFD_CONFIGURE_ENABLE=	pfd

GTKSOURCEVIEW_CONFIGURE_ENABLE=	sourceview
GTKSOURCEVIEW_USE=	GNOME=gtksourceview3

SPELL_CONFIGURE_ENABLE=	spell
SPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell \
			libenchant-2.so:textproc/enchant2

.include <bsd.port.mk>
