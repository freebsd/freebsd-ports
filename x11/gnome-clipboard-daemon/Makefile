PORTNAME=	gnome-clipboard-daemon
PORTVERSION=	1.0
PORTREVISION=	12
CATEGORIES=	x11 gnome
MASTER_SITES=	http://members.chello.nl/~h.lai/gnome-clipboard-daemon/
DISTNAME=	${PORTNAME:S,^gnome-,,}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program that keeps the content of your X clipboard in memory

LICENSE=	GPLv2

USES=		gnome pkgconfig tar:bzip2 xorg
USE_GNOME=	gtk20
USE_XORG=	x11
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} ${CPPFLAGS}"

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} \
		-e 's|-o clipboard-daemon |-o ${PORTNAME} |' \
		-e 's/gtk+-2\.0/& x11/' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
