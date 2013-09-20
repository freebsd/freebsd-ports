# Created by: Sascha Holzleiter <sascha@root-login.org>
# $FreeBSD$

PORTNAME=	idesk
PORTVERSION=	0.7.5
PORTREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Place launch icons and background directly on your desktop

LIB_DEPENDS=	Xft:${PORTSDIR}/x11-fonts/libXft

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_EFL=	imlib2
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
USES=		pkgconfig

OPTIONS_DEFINE=	SHAPE SN
SHAPE_DESC=	Support of XShape extension
SN_DESC=	Startup notification support
OPTIONS_DEFAULT=	SHAPE

NO_STAGE=	yes
.include <bsd.port.pre.mk>

CXXFLAGS+=	`imlib2-config --cflags` `freetype-config --cflags`
MAKE_ARGS=	cc="${CXX}" cflags="${CXXFLAGS}"
SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSHAPE}
CONFIGURE_ARGS+=	--enable-shape
.else
CONFIGURE_ARGS+=	--disable-shape
.endif

.if ${PORT_OPTIONS:MSN}
LIB_DEPENDS+=	startup-notification:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=	--enable-libsn
.endif

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/idesk ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
