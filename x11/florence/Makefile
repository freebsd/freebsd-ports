PORTNAME=	florence
PORTVERSION=	0.6.3
PORTREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	SF/florence/florence/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible scalable virtual keyboard
WWW=		https://florence.sourceforge.net/

LICENSE=	GPLv2+ GFDL
LICENSE_COMB=	multi

LIB_DEPENDS=	libnotify.so:devel/libnotify

USES=		gmake gnome gstreamer iconv libtool pathfix pkgconfig tar:bzip2 xorg
USE_GNOME=	gtk30 cairo intlhack librsvg2
USE_LDCONFIG=	yes
USE_XORG=	xtst xext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --without-docs

GLIB_SCHEMAS=	org.florence.gschema.xml

INSTALL_TARGET=	install-strip

MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

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
