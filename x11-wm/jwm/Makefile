# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	jwm
PORTVERSION=	2.0.1
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	SF http://joewing.net/programs/jwm/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Joe's Window Manager

LICENSE=	GPLv2

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USES=		pkgconfig
USE_XORG=	xpm
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		jwm.1

OPTIONS_DEFINE=	FRIBIDI XFT XINERAMA JPEG DEBUG
OPTIONS_DEFAULT=	FRIBIDI XFT XINERAMA JPEG
DEBUG_DESC=	Enable debugging

FRIBIDI_BUILD_DEPENDS=	fribidi:${PORTSDIR}/converters/fribidi
JPEG_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
DEBUG_CONFIGURE_ON=	--enable-debug

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXFT}
USE_XORG+=	xft
.endif

.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=	xinerama
.endif

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
	${INSTALL_MAN} ${WRKSRC}/jwm.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
