# New ports collection makefile for:    xfedor
# Version required:     ?
# Date created:         3 Sep 1996
# Whom:                 ache
#
# ATTENTION: It not work in > 256 colors modes, please fix it
# if you can.
#
# $Id: Makefile,v 1.11 1996/06/26 23:06:49 gpalmer Exp $
#

DISTNAME=       xfedor
PKGNAME=        xfedor-1.0
CATEGORIES+=	x11
MASTER_SITES=   ftp://ftp.uni-trier.de/pub/unix/X11/R6/contrib/programs/

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

MAINTAINER=     ache@FreeBSD.ORG

USE_IMAKE=      yes

XFHELP= ${X11BASE}/lib/X11/xfedor # See patches too
XCAT1= ${X11BASE}/man/cat1

do-install:
	cd ${WRKSRC}; \
	${INSTALL} -c -s -m ${BINMODE} -o ${BINOWN} -g ${BINGRP} xfedor ${PREFIX}/bin
	-mkdir -p ${XFHELP}
	chown ${SHAREOWN}.${SHAREGRP} ${XFHELP}
	chmod 755 ${XFHELP}
	cd ${WRKSRC}/help; \
	${INSTALL} -c -m ${SHAREMODE} -o ${SHAREOWN} -g ${SHAREGRP} * ${XFHELP}
	${INSTALL} -c -m ${SHAREMODE} -o ${SHAREOWN} -g ${SHAREGRP} ${FILESDIR}/default.sos ${XFHELP}
	-mkdir -p ${XCAT1}
	chown ${MANOWN}.${MANGRP} ${XCAT1}
	chmod 755 ${XCAT1}
	cd ${WRKSRC}; \
	${INSTALL} -c -m ${MANMODE} -o ${MANOWN} -g ${MANGRP} xfedor.txt ${XCAT1}/xfedor.1

.include <bsd.port.mk>
