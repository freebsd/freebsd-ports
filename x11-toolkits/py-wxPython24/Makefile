# New ports collection makefile for:    wxPython
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	py-wxPython
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wxpython
DISTNAME=	wxPython-${PORTVERSION}

MAINTAINER=	nectar@FreeBSD.ORG

LIB_DEPENDS=	wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk

USE_GMAKE=	yes
USE_NEWGCC=	yes
USE_PYTHON=	yes
USE_GTK=	yes
INSTALLS_SHLIB=	yes
MAKE_ENV=	LN_S="${LN} -s" \
		CXX="${CXX}" \
		SYSCFLAGS="`${GTK_CONFIG} --cflags`" \
		SYSLFLAGS="`${GTK_CONFIG} --libs` -L${WRKSRC}/src" \
		_TARGETDIR="${PYTHON_SITELIBDIR}/wxPython" \
		_HELPERLIBDIR="${PREFIX}/lib" \
		WRKSRC="${WRKSRC}"
ALL_TARGET=	default
INSTALL_TARGET=	install-freebsd

do-configure:
	${CP} ${FILESDIR}/build.local ${WRKSRC}/src/build.local
	${CP} ${FILESDIR}/build.local.stc ${WRKSRC}/contrib/stc/build.local
	${CP} ${FILESDIR}/build.local.ogl ${WRKSRC}/contrib/ogl/build.local
	cd ${WRKSRC}/src && ../distrib/build.py
	cd ${WRKSRC}/contrib/stc && ../../distrib/build.py
	cd ${WRKSRC}/contrib/ogl && ../../distrib/build.py

.include <bsd.port.mk>
