PORTNAME=	florence
DISTVERSION=	0.7.2
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Extensible scalable virtual keyboard
WWW=		https://github.com/FrauBSD/florence

LICENSE=	GFDL GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE_GFDL=	${WRKSRC}/COPYING-DOCS
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libnotify.so:devel/libnotify

USES=		gmake gnome gstreamer iconv libtool localbase pathfix pkgconfig \
		xorg
USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2
GLIB_SCHEMAS=	org.florence.gschema.xml
USE_GSTREAMER=	good ogg vorbis
USE_LDCONFIG=	yes
USE_XORG=	x11 xext xrandr xtst

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--without-docs

MAKE_JOBS_UNSAFE=	yes

INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS ChangeLog NEWS README.md

OPTIONS_DEFINE=			DOCS FREEBSD_ORB NLS
OPTIONS_DEFAULT=		DOCS FREEBSD_ORB NLS
OPTIONS_SUB=			yes
FREEBSD_ORB_DESC=		FreeBSD orb glyph for the Super key
FREEBSD_ORB_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-freebsd-orb-super

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|^Categories=.*|Categories=Application;Accessibility;System;|' \
		${WRKSRC}/data/florence.desktop.in.in

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|^ALL_LINGUAS.*|ALL_LINGUAS =|' \
		${WRKSRC}/po/Makefile.in.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
