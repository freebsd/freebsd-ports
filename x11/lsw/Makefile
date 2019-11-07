# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lsw
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lists the titles of all running X windows to stdout, similar to ls(1)

MAKE_ARGS=	PREFIX="${PREFIX}" X11LIB="${LOCALBASE}/lib" \
		X11INC="${LOCALBASE}/include" CC="${CC}"
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		xorg
USE_XORG=	x11 xt xorgproto xext

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/include||;s|-L/usr/lib||;s|= -Os|+=|'\
		-e 's|-DHAVE_SHADOW_H||' ${WRKSRC}/config.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
