# New ports collection makefile for:	TkStep
# Version required:	8.0
# Date created:		06 November 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1997/11/11 07:53:24 tg Exp $
#

DISTNAME=	tk8.0
PKGNAME=	tkstep-8.0
CATEGORIES=	x11 tk80
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/

PATCH_SITES=	http://rhein-zeitung.de/~ograf/files/
PATCHFILES=	tk8.0-to-TkStep8.0-2.patch.gz

MAINTAINER=	tg@FreeBSD.ORG

LIB_DEPENDS=	tcl80\\.1\\.:${PORTSDIR}/lang/tcl80 \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg \
		tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34

FETCH_BEFORE_ARGS=	-b
PATCH_DIST_ARGS=	-p -d ${WRKDIR} -E --quiet
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --enable-shared --enable-xpm --enable-step --enable-dnd \
		 --enable-tiff --with-optimize="${CFLAGS} -I${PREFIX}/include"
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

post-install:
	@${RM} ${PREFIX}/share/tkstep8.0/demos/*.orig
	strip ${PREFIX}/bin/wishstep8.0
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tkstep
	${INSTALL_DATA}	${WRKDIR}/${DISTNAME}/README.TkStep \
		${PREFIX}/share/doc/tkstep
.endif
	${LDCONFIG} -m ${PREFIX}/lib

test:
	cd ${WRKSRC}; make test

.include <bsd.port.mk>
