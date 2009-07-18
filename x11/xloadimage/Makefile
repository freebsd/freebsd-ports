# New ports collection makefile for:    xloadimage
# Date created:         9 January 1994
# Whom:                 jmz
#
# $FreeBSD$
#

VERSION=	4.1
REVISION=	16
PORTREVISION=	5

PORTNAME=	xloadimage
PORTVERSION=	${VERSION}.${REVISION}
CATEGORIES=	x11 graphics
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
DISTNAME=	${PORTNAME}.${VERSION}
PATCH_SITES=	${MASTER_SITE_DEBIAN_POOL}
PATCHFILES=	${PORTNAME}_${VERSION}-${REVISION}.diff.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 Image Loading Utility

PATCH_STRIP=	-p1
EXTRA_PATCHES=	${WRKSRC}/debian/patches/*.dpatch

USE_XORG=	x11
LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib

MAN1=		xloadimage.1 uufilter.1
MLINKS=		xloadimage.1 xsetbg.1 \
		xloadimage.1 xview.1

post-patch:
	@${CHMOD} a+rx ${WRKSRC}/configure
	@cd ${WRKSRC}; ${MV} xloadimage.man xloadimage.man.old; \
		${SED} -e s:/etc/X11/Xloadimage:${PREFIX}/etc/xloadimagerc: \
		       -e s:/usr/lib/xloadimagerc:${PREFIX}/etc/xloadimagerc: \
		< xloadimage.man.old > xloadimage.man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xloadimage ${PREFIX}/bin
	@cd ${PREFIX}/bin && \
		${LN} -sf xloadimage xsetbg && \
		${LN} -sf xloadimage xview
	${INSTALL_PROGRAM} ${WRKSRC}/uufilter ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xloadimage.man ${PREFIX}/man/man1/xloadimage.1
	${INSTALL_MAN} ${WRKSRC}/uufilter.man ${PREFIX}/man/man1/uufilter.1
	${MKDIR} ${PREFIX}/share/examples/xloadimage
	${INSTALL_DATA} ${WRKSRC}/xloadimagerc \
		${PREFIX}/share/examples/xloadimage/xloadimagerc

post-install:
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
