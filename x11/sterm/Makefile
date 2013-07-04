# Created by: Matthew Donovan <kitchetech@gmail.com>
# $FreeBSD$

PORTNAME=	sterm
PORTVERSION=	0.4.1
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/st/
DISTNAME=	st-${PORTVERSION}

MAINTAINER=	kitche@kitchetech.com
COMMENT=	Simple X terminal

LICENSE=	MITX
LICENSE_NAME=	MIT/X Consortium License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		freetype:${PORTSDIR}/print/freetype2

USES=	pkgconfig ncurses:port
USE_XORG=	x11 xext xft
MAN1=	st.1
PLIST_FILES=	bin/st

PORTDOCS=	README

.include <bsd.port.options.mk>

pre-everything::
	@${ECHO_MSG} "You can build st with your own config.h using the ST_CONF knob:"
	@${ECHO_MSG} "make ST_CONF=/path/to/st/config.h install clean"

post-patch:
.if defined(ST_CONF)
	@${ECHO_MSG} "creating config.h from ${ST_CONF}"
	@${CP} ${ST_CONF} ${WRKSRC}/config.h
.endif
	@${REINPLACE_CMD} -e 's|^VERSION = .*|VERSION = ${PORTVERSION}|' \
		-e 's|^PREFIX = .*|PREFIX = ${PREFIX}|' \
		-e 's|^LOCALBASE = .*|LOCALBASE = ${LOCALBASE}|' \
		-e "s|^MANPREFIX = .*|MANPREFIX = ${MANPREFIX}/man|" \
		-e "s|^X11INC = .*|X11INC = ${LOCALBASE}/include|" \
		-e "s|^X11LIB = .*|X11LIB = ${LOCALBASE}/lib|" \
		${WRKSRC}/config.mk

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
