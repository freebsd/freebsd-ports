# New ports collection makefile for:    wxPython
# Version required:     		2.1b3
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

DISTNAME=	wxPython-2.1b3
PKGNAME=	py-wxPython-2.1b3
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://alldunn.com/wxPython/ \
		http://www.nectar.com/distfiles/

MAINTAINER=	nectar@FreeBSD.ORG

BUILD_DEPENDS=	python1.5:${PORTSDIR}/lang/python
LIB_DEPENDS=	wx_gtk.1:${PORTSDIR}/x11-toolkits/wxgtk
RUN_DEPENDS=	python1.5:${PORTSDIR}/lang/python

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_GMAKE=	YES
USE_NEWGCC=	YES
MAKE_ENV=	"LN_S=${LN} -s" "INSTALL_DATA=${INSTALL_DATA}"
ALL_TARGET=	default
INSTALL_TARGET=	install-freebsd

TARGETDIR=	${LOCALBASE}/lib/python1.5/site-packages/wxPython
HELPERLIBDIR=	${LOCALBASE}/lib

do-configure:
	${SED} 	-e "s:%CFLAGS%:${CFLAGS} `gtk12-config --cflags`:"   \
		-e "s:%LFLAGS%:`gtk12-config --libs` -L${WRKSRC}:"   \
		-e "s:%TARGETDIR%:${TARGETDIR}:"		     \
		-e "s:%HELPERLIBDIR%:${HELPERLIBDIR}:"		     \
		-e "s:%CXX%:${CXX}:"                                 \
		${FILESDIR}/build.local > ${WRKSRC}/build.local
	cd ${WRKSRC} && ../distrib/build.py

.include <bsd.port.mk>
