PORTNAME=	yad
PORTVERSION=	14.2
DISTVERSIONPREFIX=	v
CATEGORIES=	x11 gnome

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Display GNOME dialogs from the command line
WWW=		https://github.com/v1cont/yad

LICENSE=	GPLv3

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/lib/X11/rgb.txt:x11/rgb

USES=		autoreconf gettext gnome gmake pkgconfig

USE_GNOME=	cairo gtk30
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	DATADIRNAME=share
CONFIGURE_ARGS+=	--with-rgb=${LOCALBASE}/lib/X11/rgb.txt
GLIB_SCHEMAS=	yad.gschema.xml

USE_GITHUB=	yes
GH_ACCOUNT=	v1cont

OPTIONS_DEFINE=	HTML ICONBROWSER NLS GTKSOURCEVIEW SPELL TOOLS
HTML_DESC=		Build with HTML widget
ICONBROWSER_DESC=	Build YAD icon browser
GTKSOURCEVIEW_DESC=	Build with GtkSourceView support
SPELL_DESC=		Build with Spell check support
TOOLS_DESC=		Build with yad-tools utility
OPTIONS_DEFAULT=	SPELL
OPTIONS_SUB=	yes

HTML_CONFIGURE_ENABLE=	html
HTML_LIB_DEPENDS=	libwebkit2gtk-4.1.so:www/webkit2-gtk@41 \
			libsoup-3.0.so:devel/libsoup3 \
			libjavascriptcoregtk-4.1.so:www/webkit2-gtk@41

ICONBROWSER_CONFIGURE_ENABLE=	icon-browser

GTKSOURCEVIEW_CONFIGURE_ENABLE=	sourceview
GTKSOURCEVIEW_USE=	GNOME=gtksourceview3

SPELL_CONFIGURE_ENABLE=	spell
SPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell \
			libenchant-2.so:textproc/enchant2

TOOLS_CONFIGURE_ENABLE=	tools

.include <bsd.port.mk>
