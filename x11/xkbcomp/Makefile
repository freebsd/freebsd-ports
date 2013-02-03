# $FreeBSD$

PORTNAME=	xkbcomp
PORTVERSION=	1.2.4
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Compile XKB keyboard description

LICENSE=	MIT

XORG_CAT=	app
USE_XORG=	x11 xkbfile

PLIST_FILES=	bin/xkbcomp \
		libdata/pkgconfig/xkbcomp.pc

MAN1=		xkbcomp.1

post-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
	    ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
