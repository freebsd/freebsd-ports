# New ports collection makefile for:	py-gtk2
# Date created:				08/13/2002
# Whom:					marc@informatik.uni-bremen.de
#
# $FreeBSD$

PORTNAME=	gtk
PORTVERSION=	1.99.12
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/pygtk/1.99
DISTNAME=	pygtk-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	gnome2

MAINTAINER=	marc@informatik.uni-bremen.de

LIB_DEPENDS=	gtk-x11-2.0:${PORTSDIR}/x11-toolkits/gtk20 \
		glade-2.0.0:${PORTSDIR}/devel/libglade2 \
		gtkgl-2.0:${PORTSDIR}/x11-toolkits/gtkglarea2
RUN_DEPENDS=	${PYNUMERIC}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_PYTHON=	yes
USE_LIBTOOL=	yes

EG_SRC_DIR=	${WRKSRC}/examples
EG_DST_DIR=	${PREFIX}/share/examples/py-gtk

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
pre-build:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EG_DST_DIR}
	${TAR} -C ${EG_SRC_DIR} -cf - . | ${TAR} -C ${EG_DST_DIR} -xf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EG_DST_DIR}
	${FIND} ${EG_DST_DIR} -type d -print | ${XARGS} ${CHMOD} 0555
	${FIND} ${EG_DST_DIR} -type f -print | ${XARGS} ${CHMOD} 0444
	${MKDIR} ${PREFIX}/share/doc/py-gtk
	${INSTALL_DATA} ${WRKSRC}/MAPPING ${PREFIX}/share/doc/py-gtk
	${INSTALL_DATA} ${WRKSRC}/THREADS ${PREFIX}/share/doc/py-gtk
.endif

.include <bsd.port.mk>
