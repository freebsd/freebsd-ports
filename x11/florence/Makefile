# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	florence
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	SF/florence/florence/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible scalable virtual keyboard

LICENSE=	GPLv2+ GFDL
LICENSE_COMB=	multi

LIB_DEPENDS=	libnotify.so:devel/libnotify

USES=		gmake gnome iconv libtool pathfix pkgconfig tar:bzip2 xorg
USE_XORG=	xtst xext
USE_GNOME=	gtk30 cairo intlhack gnomedocutils librsvg2
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
GLIB_SCHEMAS=	org.florence.gschema.xml
INSTALL_TARGET=	install-strip

MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

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
