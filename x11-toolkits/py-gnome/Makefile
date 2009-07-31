# New ports collection makefile for:	py-gnome
# Date created:				3/14/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	py-gnome
PORTVERSION=	1.4.4
PORTREVISION=	10
CATEGORIES=	x11-toolkits python gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gnome-python/1.4
DISTNAME=	gnome-python-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of Python bindings for GNOME

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	gtkhtml gnometarget pygtk
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-python=${PYTHON_CMD}				\
		--with-gnome-config=${LOCALBASE}/bin/gnome-config		\
		--with-gtkhtml

EG_SRC_DIR=	${WRKSRC}/pygnome/examples
EG_DST_DIR=	${EXAMPLESDIR}

CONFLICTS=	py*-gnome-2*

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' \
		${WRKSRC}/configure ${WRKSRC}/pygtk/configure

.if !defined(NOPORTEXAMPLES)
post-install:
	${MKDIR} ${EG_DST_DIR}
	${TAR} -C ${EG_SRC_DIR} -cf - . | ${TAR} -C ${EG_DST_DIR} -xvf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EG_DST_DIR}
	${FIND} ${EG_DST_DIR} -type d -print | ${XARGS} ${CHMOD} 0555
	${FIND} ${EG_DST_DIR} -type f -print | ${XARGS} ${CHMOD} 0444
.endif

.include <bsd.port.mk>
