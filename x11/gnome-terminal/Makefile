PORTNAME=	gnome-terminal
DISTVERSION=	3.54.5
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the GNOME Desktop
WWW=		https://gitlab.gnome.org/GNOME/gnome-terminal

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool
LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libhandy-1.so:x11-toolkits/libhandy \
		libuuid.so:misc/libuuid
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		cpe gettext gnome localbase meson pkgconfig python \
		tar:xz vala:build xorg
USE_GNOME=	cairo dconf gdkpixbuf gtk30 vte3 libxslt:build
USE_XORG=	x11
CPE_VENDOR=	gnome

MESON_ARGS=	-Ddocs=false

GLIB_SCHEMAS=	org.gnome.Terminal.gschema.xml

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=		NAUTILUS SEARCHPROVIDER
OPTIONS_SUB=		yes

SEARCHPROVIDER_DESC=		GNOME Shell search provider
SEARCHPROVIDER_MESON_TRUE=	search_provider
SEARCHPROVIDER_BUILD_DEPENDS=	gnome-shell:x11/gnome-shell
SEARCHPROVIDER_RUN_DEPENDS=	gnome-shell:x11/gnome-shell

NAUTILUS_MESON_TRUE=	nautilus_extension
NAUTILUS_USE=		GNOME=nautilus4
NAUTILUS_DESC=		Open in terminal extension for nautilus

post-patch:
	${REINPLACE_CMD} -e 's|SystemdService|#SystemdService|' \
		${WRKSRC}/src/org.gnome.Terminal.service.in

.include <bsd.port.mk>
