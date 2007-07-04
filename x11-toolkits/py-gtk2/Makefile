# New ports collection makefile for:	py-gtk2
# Date created:				08/13/2002
# Whom:					marc@informatik.uni-bremen.de
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/py-gtk2/Makefile,v 1.49 2006/10/03 20:52:30 ahze Exp $
#

PORTNAME=	gtk
PORTVERSION=	2.10.5
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/pygtk/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygtk-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of Python bindings for GTK+

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py-cairo \
		${PYTHON_SITELIBDIR}/gtk-2.0/gobject/_gobject.so:${PORTSDIR}/devel/py-gobject
RUN_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py-cairo \
		${PYTHON_SITELIBDIR}/gtk-2.0/gobject/_gobject.so:${PORTSDIR}/devel/py-gobject

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget libglade2
USE_PYTHON=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-lintl" \
		PYTHON="${PYTHON_VERSION}"
CONFIGURE_ARGS=	--disable-docs
LDFLAGS+=	-L${LOCALBASE}/lib

DOCSDIR=	${PREFIX}/share/doc/py-gtk
EG_SRC_DIR=	${WRKSRC}/examples
EXAMPLESDIR=	${PREFIX}/share/examples/py-gtk

CONFLICTS=	py*-gtk-0*

#
# Use the same way as the Python port to determine if we want
# threading support.
#
.if !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--enable-thread
CFLAGS+=		${PTHREAD_CFLAGS}
CONFIGURE_ENV+=		LDFLAGS="${PTHREAD_LIBS} ${LDFLAGS}"
.else
CONFIGURE_ARGS+=	--disable-thread
.if defined(LDFLAGS)
CONFIGURE_ENV+=		LDFLAGS="${LDFLAGS}"
.endif
.endif

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${EG_SRC_DIR} -cf - . | ${TAR} -C ${EXAMPLESDIR} -xf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EXAMPLESDIR}
	${FIND} ${EXAMPLESDIR} -type d -print | ${XARGS} ${CHMOD} 0555
	${FIND} ${EXAMPLESDIR} -type f -print | ${XARGS} ${CHMOD} 0444
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MAPPING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/THREADS ${DOCSDIR}
.endif

.include <bsd.port.mk>
