# New ports collection makefile for:	py-gtk
# Date created:				09/14/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	py-gtk
PORTVERSION=	0.6.10
PORTREVISION=	1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-python/1.4
DISTNAME=	gnome-python-1.4.4
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of Python bindings for GTK

BUILD_DEPENDS=	${PYNUMERIC}
LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea
RUN_DEPENDS=	${PYNUMERIC}

WRKSRC=		${WRKDIR}/${DISTNAME}/pygtk

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomelibs gdkpixbuf libglade
USE_PYTHON=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	PYTHON=${PYTHON_CMD}
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

EG_SRC_DIR=	${WRKSRC}/examples
EG_DST_DIR=	${PREFIX}/share/examples/py-gtk

CONFLICTS=	py*-gtk-2*

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EG_DST_DIR}
	${TAR} -C ${EG_SRC_DIR} -cf - . | ${TAR} -C ${EG_DST_DIR} -xvf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EG_DST_DIR}
	${FIND} ${EG_DST_DIR} -type d -print | ${XARGS} ${CHMOD} 0555
	${FIND} ${EG_DST_DIR} -type f -print | ${XARGS} ${CHMOD} 0444
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
