# Created by: jmz
# $FreeBSD$

PORTNAME=	xloadimage
PORTVERSION=	4.1.21
PORTREVISION=	1
CATEGORIES=	x11 graphics
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}.${VERSION}
DISTFILES=	${DISTNAME:S/./_/}.orig${EXTRACT_SUFX} \
		${DISTNAME:S/./_/}-${REVISION}.debian.tar.gz

MAINTAINER=	ak@FreeBSD.org
COMMENT=	X11 Image Loading Utility

LICENSE=	MIT

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

CONFLICTS_INSTALL=	xli-*

EXTRA_PATCHES=	${WRKDIR}/debian/patches/*.patch

PATCH_STRIP=	-p1
VERSION=	${PORTVERSION:R}
REVISION=	${PORTVERSION:E}

USES=		jpeg
USE_XORG=	x11
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${CHMOD} a+rx ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|TIFFHeader|TIFFHeaderClassic|g' \
		${WRKSRC}/tiff.c
	@${REINPLACE_CMD} -e \
		's:/etc/X11/Xloadimage:${PREFIX}/etc/xloadimagerc: ; \
		 s:/usr/lib/xloadimagerc:${PREFIX}/etc/xloadimagerc: ; \
		 s:/usr/include/X11/bitmaps:${PREFIX}/include/X11/bitmaps:' \
		${WRKSRC}/xloadimage.man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xloadimage ${STAGEDIR}${PREFIX}/bin
	@(cd ${STAGEDIR}${PREFIX}/bin && \
		${LN} -sf xloadimage xsetbg && \
		${LN} -sf xloadimage xview )
	${INSTALL_PROGRAM} ${WRKSRC}/uufilter ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/uufilter.man ${STAGEDIR}${MAN1PREFIX}/man/man1/uufilter.1
	${INSTALL_MAN} ${WRKSRC}/xloadimage.man ${STAGEDIR}${MAN1PREFIX}/man/man1/xloadimage.1
	@(cd ${STAGEDIR}${MAN1PREFIX}/man/man1 && \
		${LN} -sf xloadimage.1 xsetbg.1 && \
		${LN} -sf xloadimage.1 xview.1 )
	${INSTALL_DATA} ${WRKSRC}/xloadimagerc ${STAGEDIR}${PREFIX}/etc/xloadimagerc.sample

.include <bsd.port.mk>
