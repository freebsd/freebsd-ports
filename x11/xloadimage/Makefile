# New ports collection makefile for:    xloadimage
# Date created:         9 January 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	xloadimage
PORTVERSION=	4.1.17
CATEGORIES=	x11 graphics
MASTER_SITES=	ftp://ftp.x.org/R5contrib/:x11 \
		${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}.${VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:x11 \
		${PORTNAME}_${VERSION}-${REVISION}.debian.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 Image Loading Utility

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

LICENCE=	MIT

CONFLICTS_INSTALL=	xli-*

EXTRA_PATCHES=	${WRKDIR}/debian/patches/*.dpatch

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
		 s:/usr/lib/xloadimagerc:${PREFIX}/etc/xloadimagerc:' \
		${WRKSRC}/xloadimage.man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xloadimage ${PREFIX}/bin
	@cd ${PREFIX}/bin && \
		${LN} -sf xloadimage xsetbg && \
		${LN} -sf xloadimage xview
	${INSTALL_PROGRAM} ${WRKSRC}/uufilter ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xloadimage.man ${MANPREFIX}/man/man1/xloadimage.1
	${INSTALL_MAN} ${WRKSRC}/uufilter.man ${MANPREFIX}/man/man1/uufilter.1
	${INSTALL_DATA} ${WRKSRC}/xloadimagerc ${PREFIX}/etc/xloadimagerc.sample
.if !exists(${PREFIX}/etc/xloadimagerc)
	@cd ${PREFIX}/etc && ${CP} -f xloadimagerc.sample xloadimagerc
.endif

.include <bsd.port.mk>
