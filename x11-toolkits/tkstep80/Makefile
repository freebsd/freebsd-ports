# New ports collection makefile for:	TkStep
# Version required:	8.0p2
# Date created:		06 November 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.9 1998/07/03 23:07:17 steve Exp $
#

DISTNAME=	tk8.0p2
PKGNAME=	tkstep-8.0p2
CATEGORIES=	x11 tk80
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_0/

PATCH_SITES=	http://rhein-zeitung.de/~ograf/files/ \
		http://www.uni-koblenz.de/~ograf/files/
PATCHFILES=	tk8.0p2-to-TkStep8.0p2-1.patch.gz

MAINTAINER=	tg@FreeBSD.ORG

LIB_DEPENDS=	tcl80\\.1\\.:${PORTSDIR}/lang/tcl80 \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34

FETCH_BEFORE_ARGS=	-b
PATCH_DIST_ARGS=	-p1 -d ${WRKDIR}/tk8.0 -E --quiet
WRKSRC=		${WRKDIR}/tk8.0/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-shared --enable-xpm --enable-step --enable-dnd \
		 --enable-tiff --with-optimize="${CFLAGS} -I${PREFIX}/include -I${PREFIX}/include/tiff34"
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

post-install:
	@${RM} ${PREFIX}/share/tkstep8.0/demos/*.orig
	strip ${PREFIX}/bin/wishstep8.0
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tkstep
	${INSTALL_DATA}	${WRKDIR}/tk8.0/README.TkStep \
		${PREFIX}/share/doc/tkstep
.endif
	${LDCONFIG} -m ${PREFIX}/lib
.if exists(${PORTSDIR}/x11/tk80/pkg/INSTALL.wish)
	${SH} ${PORTSDIR}/x11/tk80/pkg/INSTALL.wish
.endif

test:
	cd ${WRKSRC}; make test

.include <bsd.port.mk>

PKG_ARGS+=      -i ${PORTSDIR}/x11/tk80/pkg/INSTALL.wish
