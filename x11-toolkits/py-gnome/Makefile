# New ports collection makefile for:	py-gnome
# Date created:				3/14/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	py-gnome
PORTVERSION=	1.4.4
PORTREVISION=	3
CATEGORIES=	x11-toolkits python gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-python/1.4
DISTNAME=	gnome-python-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of Python bindings for GNOME

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/pygtk.pth:${PORTSDIR}/x11-toolkits/py-gtk
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygtk.pth:${PORTSDIR}/x11-toolkits/py-gtk

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	gtkhtml gnometarget
USE_INC_LIBTOOL_VER=13
LIBTOOLFILES=	configure pygtk/configure
CONFIGURE_ARGS=	--with-python=${PYTHON_CMD}				\
		--with-gnome-config=${X11BASE}/bin/gnome-config		\
		--with-gtkhtml

EG_SRC_DIR=	${WRKSRC}/pygnome/examples
EG_DST_DIR=	${PREFIX}/share/examples/py-gnome

CONFLICTS=	py*-gnome-2*

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EG_DST_DIR}
	${TAR} -C ${EG_SRC_DIR} -cf - . | ${TAR} -C ${EG_DST_DIR} -xvf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EG_DST_DIR}
	${FIND} ${EG_DST_DIR} -type d -print | ${XARGS} ${CHMOD} 0555
	${FIND} ${EG_DST_DIR} -type f -print | ${XARGS} ${CHMOD} 0444
.else
PLIST=		${WRKDIR}/PLIST.nodocs
pre-install:
	${RM} -f ${PLIST}
	${GREP} -E -v '^(@dirrm )?(share/examples/)|(share/doc/)'       \
		${PKGDIR}/pkg-plist > ${PLIST}
.endif

.include <bsd.port.mk>
