# New ports collection makefile for:	py-gtk
# Date created:				09/14/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gtk
PORTVERSION=	0.6.11
PORTREVISION=	8
CATEGORIES=	x11-toolkits python
MASTER_SITES=	GNOME
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
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
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHON=${PYTHON_CMD}

PORTDOCS=	MAPPING
EG_SRC_DIR=	${WRKSRC}/examples

CONFLICTS=	py*-gtk-2* py*-gobject-[0-9]*

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MAPPING ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${EG_SRC_DIR} -cf - . | ${TAR} -C ${EXAMPLESDIR} -xvf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EXAMPLESDIR}
	${FIND} ${EXAMPLESDIR} -type d -print | ${XARGS} ${CHMOD} 0555
	${FIND} ${EXAMPLESDIR} -type f -print | ${XARGS} ${CHMOD} 0444
.endif

.include <bsd.port.mk>
