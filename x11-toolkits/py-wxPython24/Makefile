# New ports collection makefile for:    wxPython
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	py-wxPython
PORTVERSION=	2.2.1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://alldunn.com/wxPython/dist/
DISTNAME=	wxPython-${PORTVERSION}

MAINTAINER=	nectar@FreeBSD.ORG

BUILD_DEPENDS=	wx-config:${PORTSDIR}/x11-toolkits/wxgtk
LIB_DEPENDS=	wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_GMAKE=	yes
USE_NEWGCC=	yes
USE_PYTHON=	yes
USE_GTK=	yes
MAKE_ENV=	"LN_S=${LN} -s" "INSTALL_DATA=${INSTALL_DATA}"
ALL_TARGET=	default
INSTALL_TARGET=	install-freebsd

TARGETDIR=	${PREFIX}/lib/python1.5/site-packages/wxPython
TARGETDIR=	${PYTHON_SITELIBDIR}/wxPython
HELPERLIBDIR=	${PREFIX}/lib

do-configure:
	${SED} 	-e "s:%CFLAGS%:${CFLAGS} `${GTK_CONFIG} --cflags`:"   \
		-e "s:%LFLAGS%:`${GTK_CONFIG} --libs` -L${WRKSRC}:"   \
		-e "s:%TARGETDIR%:${TARGETDIR}:"		     \
		-e "s:%HELPERLIBDIR%:${HELPERLIBDIR}:"		     \
		-e "s:%CXX%:${CXX}:" -e "s:%WRKSRC%:${WRKSRC}:"      \
		${FILESDIR}/build.local > ${WRKSRC}/../build.local
	cd ${WRKSRC} && ../distrib/build.py

.include <bsd.port.mk>
