# New ports collection makefile for:	py-gnome
# Date created:				09 February 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-gnome
PORTVERSION=	1.99.15
PORTREVISION=	1
CATEGORIES=	x11-toolkits python gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-python/1.99
DISTNAME=	gnome-python-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of Python bindings for GNOME 2

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/_gtkmodule.so:${PORTSDIR}/x11-toolkits/py-gtk2
LIB_DEPENDS=	gnomeprintui-2-2.0:${PORTSDIR}/x11-toolkits/libgnomeprintui \
		gtkhtml-2.0:${PORTSDIR}/www/libgtkhtml \
		panel-applet-2.0:${PORTSDIR}/x11/gnomepanel \
		zvt-2.0.0:${PORTSDIR}/x11-toolkits/libzvt \
		nautilus.2:${PORTSDIR}/x11-fm/nautilus2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/_gtkmodule.so:${PORTSDIR}/x11-toolkits/py-gtk2

LATEST_LINK=	py-gnome2
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

EG_SRC_DIR=	${WRKSRC}/examples
EG_DST_DIR=	${PREFIX}/share/examples/py-gnome

.if !defined(PACKAGE_BUILDING)
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
.endif

.include <bsd.port.mk>
