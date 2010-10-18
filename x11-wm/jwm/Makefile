# New ports collection makefile for:   jwm
# Date created:        26 DEC 2005
# Whom:                babak@farrokhi.net
#
# $FreeBSD$
#

PORTNAME=	jwm
PORTVERSION=	2.0.1
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	SF \
		http://joewing.net/programs/jwm/releases/

MAINTAINER=	admin@mjbrune.org
COMMENT=	Joe's Window Manager

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_XORG=	xpm
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		jwm.1

OPTIONS=	FRIBIDI "Fribidi support"       on \
		XFT     "Xft support    "       on \
		XINERAMA "XINERAMA support"     on \
		JPEG    "JPEG support"          on \
		DEBUG   "Enable Debugging"      off

.include <bsd.port.options.mk>

.if defined(WITH_FRIBIDI)
BUILD_DEPENDS+=         fribidi:${PORTSDIR}/converters/fribidi
.endif

.if defined(WITH_XFT)
LIB_DEPENDS+=           Xft:${PORTSDIR}/x11-fonts/libXft
.endif

.if defined(WITH_XINERAMA)
LIB_DEPENDS+=           Xinerama:${PORTSDIR}/x11/libXinerama

.endif

.if defined(WITH_JPEG)
LIB_DEPENDS+=   jpeg:${PORTSDIR}/graphics/jpeg
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=        --enable-debug
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/example.jwmrc
	@${REINPLACE_CMD} -e 's|fribidi_char_sets_utf8.h|fribidi-char-sets.h|' ${WRKSRC}/src/jwm.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/jwm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/example.jwmrc ${PREFIX}/etc/system.jwmrc.sample
	if ! [ -f ${PREFIX}/etc/system.jwmrc ]; then \
		${INSTALL_DATA} ${WRKSRC}/example.jwmrc ${PREFIX}/etc/system.jwmrc; \
	fi
	${INSTALL_MAN} ${WRKSRC}/jwm.1 ${MANPREFIX}/man/man1/

.include <bsd.port.post.mk>
