# $FreeBSD$

PORTNAME=	wev
PORTVERSION=	1.0.0
CATEGORIES=	x11
MASTER_SITES=	https://git.sr.ht/~sircmpwn/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland event viewer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols \
		scdoc:textproc/scdoc
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gmake pkgconfig
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's/ -lrt//' ${WRKSRC}/Makefile

.include <bsd.port.mk>
