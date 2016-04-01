# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	musca
PORTVERSION=	0.9.24
CATEGORIES=	x11-wm
MASTER_SITES=	http://aerosuidae.net/ \
		http://mirror.mcx2.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple window manager for X, with features from ratpoison and dwm

BROKEN=		unfetchable

RUN_DEPENDS=	dmenu:x11/dmenu

USE_XORG=	x11
MAKE_ARGS=	CFLAGS="-I${LOCALBASE}/include \
		-L${LOCALBASE}/lib"

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
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
