# Created by: Sascha Holzleiter <sascha@root-login.org>
# $FreeBSD$

PORTNAME=	idesk
PORTVERSION=	0.7.5
PORTREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Place launch icons and background directly on your desktop

LIB_DEPENDS=	libXft.so:${PORTSDIR}/x11-fonts/libXft

USE_BZIP2=	yes
USE_EFL=	imlib2
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
USES=		gmake pkgconfig

OPTIONS_DEFINE=	SHAPE SN DOCS
SHAPE_DESC=	Support of XShape extension
SN_DESC=	Startup notification support
OPTIONS_DEFAULT=	SHAPE

CXXFLAGS+=	`imlib2-config --cflags` `freetype-config --cflags`
MAKE_ARGS=	cc="${CXX}" cflags="${CXXFLAGS}"
SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

SHAPE_CONFIGURE_ENABLE=	shape
SN_LIB_DEPENDS=	libstartup-notification.so:${PORTSDIR}/x11/startup-notification
SN_CONFIGURE_ENABLE=	libsn

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/idesk ${STAGEDIR}${PREFIX}/bin
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
