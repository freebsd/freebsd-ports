# New ports collection makefile for:	TkStep
# Date created:		06 November 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkstep
PORTVERSION=	8.0.4
PORTREVISION=	2
CATEGORIES=	x11-toolkits tk80
MASTER_SITES=	${MASTER_SITE_TCLTK}
MASTER_SITE_SUBDIR=	tcl8_0
DISTNAME=	tk${PORTVERSION}

PATCH_SITES=	ftp://touchwood.ee.uts.edu.au/pub/TkSTEP/
PATCHFILES=	tk8.0.4-to-tkstep8.0.4-2.patch.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Tk toolkit with a NeXTSTEP look and more

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_TCL=	80
USE_XORG=	xpm
PATCH_DIST_ARGS=	-p1 -d ${WRKDIR}/tk8.0.4 -E --quiet
WRKSRC=		${WRKDIR}/tk8.0.4/unix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-xpm --enable-step --enable-dnd \
		 --enable-tiff --with-optimize="${CFLAGS} -I${PREFIX}/include"
CONFIGURE_ENV=	PORTSDIR=${PORTSDIR}
PKGINSTALL=	${PORTSDIR}/x11-toolkits/tk82/pkg-install.wish
PKGDEINSTALL=	${PORTSDIR}/x11-toolkits/tk82/pkg-deinstall.wish

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Build fails on sparc64
.endif

post-install:
	@${RM} ${PREFIX}/lib/tkstep8.0/demos/*.orig
	${STRIP_CMD} ${PREFIX}/bin/wishstep8.0
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tkstep
	${INSTALL_DATA}	${WRKDIR}/tk8.0.4/README.TkStep \
		${PREFIX}/share/doc/tkstep
.endif
	${LN} -sf ${PREFIX}/lib/libtkstep80.so.1  ${PREFIX}/lib/libtkstep80.so
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

test:
	cd ${WRKSRC}; make test

.include <bsd.port.post.mk>
