# New ports collection makefile for:	idesk
# Date created:		16 February 2003
# Whom:			Sascha Holzleiter <sascha@root-login.org>
#
# $FreeBSD$
#

PORTNAME=	idesk
PORTVERSION=	0.7.5
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Place launch icons and background directly on your desktop

BUILD_DEPENDS=	imlib2-config:${PORTSDIR}/graphics/imlib2

USE_XLIB=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:259
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

CXXFLAGS+=	`imlib2-config --cflags` `freetype-config --cflags`
MAKE_ARGS=	cc="${CXX}" cflags="${CXXFLAGS}"
SUB_FILES=	pkg-message

OPTIONS=	XFT	"XFT antialias support"	on \
		SHAPE	"Enable support of the XShape extension"	on \
		SN	"Startup notification support"	off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_XFT)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-xft
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

.if !defined(WITHOUT_SHAPE)
CONFIGURE_ARGS+=	--enable-shape
.else
CONFIGURE_ARGS+=	--disable-shape
.endif

.if defined(WITH_SN)
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=	--enable-libsn
.endif

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/idesk ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
