# New ports collection makefile for:    xfedor
# Version required:     1994 year version with Imakefile
# Date created:         3 Sep 1996
# Whom:                 ache
#
# ATTENTION: It not work in > 256 colors modes, please fix it
# if you can.
#
# $Id: Makefile,v 1.6 1998/09/15 11:13:39 asami Exp $
#

DISTNAME=       xfedor
PKGNAME=        xfedor-1.0
CATEGORIES=	x11
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/x11/util/

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

MAINTAINER=     ache@FreeBSD.ORG

USE_IMAKE=      yes

XFHELP= ${X11BASE}/lib/X11/xfedor # See patches too
XCAT1= ${X11BASE}/man/cat1

do-install:
	cd ${WRKSRC}; \
	${INSTALL_PROGRAM} xfedor ${PREFIX}/bin
	-mkdir -p ${XFHELP}
	chown ${SHAREOWN}.${SHAREGRP} ${XFHELP}
	chmod 755 ${XFHELP}
	cd ${WRKSRC}/help; \
	${INSTALL_DATA} * ${XFHELP}
	${INSTALL_DATA} ${FILESDIR}/default.sos ${XFHELP}
	cd ${WRKSRC}; \
	${INSTALL_MAN} xfedor.txt ${XCAT1}/xfedor.1

.include <bsd.port.mk>
