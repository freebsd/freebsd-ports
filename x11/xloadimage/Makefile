# Created by: jmz
# $FreeBSD$

PORTNAME=	xloadimage
PORTVERSION=	4.1.21
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}.${VERSION}
DISTFILES=	${DISTNAME:S/./_/}.orig${EXTRACT_SUFX} \
		${DISTNAME:S/./_/}-${REVISION}.debian.tar.gz

MAINTAINER=	ak@FreeBSD.org
COMMENT=	X11 Image Loading Utility

LICENSE=	MIT

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff

CONFLICTS_INSTALL=	xli-*

EXTRA_PATCHES=	${WRKDIR}/debian/patches/*.patch

PATCH_STRIP=	-p1
VERSION=	${PORTVERSION:R}
REVISION=	${PORTVERSION:E}

USE_XORG=	x11
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		xloadimage.1 uufilter.1
MLINKS=		xloadimage.1 xsetbg.1 \
		xloadimage.1 xview.1

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
	${INSTALL_PROGRAM} ${WRKSRC}/xloadimage ${PREFIX}/bin
	@cd ${PREFIX}/bin && \
		${LN} -sf xloadimage xsetbg && \
		${LN} -sf xloadimage xview
	${INSTALL_PROGRAM} ${WRKSRC}/uufilter ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xloadimage.man ${MAN1PREFIX}/man/man1/xloadimage.1
	${INSTALL_MAN} ${WRKSRC}/uufilter.man ${MAN1PREFIX}/man/man1/uufilter.1
	${INSTALL_DATA} ${WRKSRC}/xloadimagerc ${PREFIX}/etc/xloadimagerc.sample
	@[ -f ${PREFIX}/etc/xloadimagerc ] || ${CP} -f ${PREFIX}/etc/xloadimagerc.sample \
                ${PREFIX}/etc/xloadimagerc

.include <bsd.port.mk>
