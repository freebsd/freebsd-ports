# New ports collection makefile for:	py-gnome
# Date created:				3/14/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	py-gnome
PORTVERSION=	1.4.2
CATEGORIES=	x11-toolkits python gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-python
DISTNAME=	gnome-python-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_gtkmodule.so:${PORTSDIR}/x11-toolkits/py-gtk
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_gtkmodule.so:${PORTSDIR}/x11-toolkits/py-gtk

USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-python=${PYTHON_CMD}				\
		--with-gnome-config=${X11BASE}/bin/gnome-config		\
		--with-gtkhtml

EG_SRC_DIR=	${WRKSRC}/pygnome/examples
EG_DST_DIR=	${PREFIX}/share/examples/py-gnome

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EG_DST_DIR}
	${TAR} -C ${EG_SRC_DIR} -cf - . | ${TAR} -C ${EG_DST_DIR} -xvf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EG_DST_DIR}
	find ${EG_DST_DIR} -type d -print | xargs ${CHMOD} 0555
	find ${EG_DST_DIR} -type f -print | xargs ${CHMOD} 0444
.else
PLIST=		${WRKDIR}/PLIST.nodocs
pre-install:
	${RM} -f ${PLIST}
	${GREP} -E -v '^(@dirrm )?(share/examples/)|(share/doc/)'       \
		${PKGDIR}/pkg-plist > ${PLIST}
.endif

.include <bsd.port.mk>
