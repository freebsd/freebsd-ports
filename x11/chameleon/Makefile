# New ports collection makefile for:	chameleon
# Date created:		17 Jan 2003
# Whom:			Gavin Atkinson <gavin.atkinson@ury.york.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	chameleon
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	http://ftp.us.debian.org/debian/pool/main/c/chameleon/ \
		ftp://carroll.aset.psu.edu/pub/linux/distributions/debian/pool/main/c/chameleon/ \
		http://www.mirrorservice.org/sites/ftp.debian.org/debian/pool/main/c/chameleon/ \
		ftp://ftp.debian.org/debian/pool/main/c/chameleon/
PKGNAMEPREFIX=	x11-
DISTNAME=	chameleon_${PORTVERSION}.orig

MAINTAINER=	gavin.atkinson@ury.york.ac.uk
COMMENT=	Application for putting pictures or colors onto the root window

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib

USE_GNOME=	gtk12

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PIXMAPSDIR=	${PREFIX}/share/pixmaps/

MAN1=		chameleon.1

MAKEFILE=	${FILESDIR}/Makefile

post-patch:
	${GUNZIP_CMD} ${WRKSRC}/${PORTNAME}.1.gz

pre-install:
	@if test ! -d ${PIXMAPSDIR}; then \
		${MKDIR} ${PIXMAPSDIR}; ${CHMOD} 0755 ${PIXMAPSDIR}; fi

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
