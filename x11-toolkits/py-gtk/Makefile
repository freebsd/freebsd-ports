# New ports collection makefile for:	py-gtk
# Date created:				09/14/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	py-gtk
PORTVERSION=	0.6.9
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-python	
DISTNAME=	gnome-python-1.4.2

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/py-numeric
LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/py-numeric

WRKSRC=		${WRKDIR}/${DISTNAME}/pygtk

USE_GMAKE=	yes
USE_GNOME=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHON=${PYTHON_CMD}
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share \
		--datadir=${PREFIX}/share
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

EG_SRC_DIR=	${WRKSRC}/examples
EG_DST_DIR=	${PREFIX}/share/examples/py-gtk

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EG_DST_DIR}
	${TAR} -C ${EG_SRC_DIR} -cf - . | ${TAR} -C ${EG_DST_DIR} -xvf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EG_DST_DIR}
	find ${EG_DST_DIR} -type d -print | xargs ${CHMOD} 0555
	find ${EG_DST_DIR} -type f -print | xargs ${CHMOD} 0444
	${MKDIR} ${PREFIX}/share/doc/py-gtk
	${INSTALL_DATA} ${WRKSRC}/MAPPING ${PREFIX}/share/doc/py-gtk
.else
PLIST=		${WRKDIR}/PLIST.nodocs
pre-install:
	${RM} -f ${PLIST}
	${GREP} -E -v '^(@dirrm )?(share/examples/)|(share/doc/)'       \
		${PKGDIR}/pkg-plist > ${PLIST}
.endif

.include <bsd.port.mk>
