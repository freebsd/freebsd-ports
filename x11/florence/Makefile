# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	florence
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	SF/florence/florence/${PORTVERSION}/

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Extensible scalable virtual keyboard

LICENSE=	GPLv2 GFDL
LICENSE_COMB=	dual

LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify
BUILD_DEPENDS=	${LOCALBASE}/libexec/at-spi2-registryd:${PORTSDIR}/accessibility/at-spi2-core
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake iconv pathfix pkgconfig tar:bzip2
USE_XORG=	xtst xext
USE_GNOME=	gtk30 cairo intlhack gnomedocutils librsvg2
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${LOCALBASE}
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
GLIB_SCHEMAS=	org.florence.gschema.xml

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^Categories=.*|Categories=Application;Accessibility;System;|' \
		${WRKSRC}/data/florence.desktop.in.in

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|^ALL_LINGUAS.*|ALL_LINGUAS =|' \
		${WRKSRC}/po/Makefile.in.in
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
