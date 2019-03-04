# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	musca
PORTVERSION=	0.9.24
CATEGORIES=	x11-wm
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/ # NETBSD (pkgsrc)

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple dynamic window manager with tiling and stacking modes

LICENSE=	GPLv3

RUN_DEPENDS=	dmenu:x11/dmenu

USES=		pkgconfig tar:tgz
USE_XORG=	x11

PLIST_FILES=	bin/musca \
		man/man1/musca.1.gz

pre-everything::
	@${ECHO_MSG} "You can build musca with your own config.h using the MUSCA_CONF knob:"
	@${ECHO_MSG} "make MUSCA_CONF=/path/to/musca/config.h install clean"

post-extract:
.if defined(MUSCA_CONF)
	@${ECHO_MSG} "creating config.h from ${MUSCA_CONF}"
	@${CP} ${MUSCA_CONF} ${WRKSRC}/config.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
