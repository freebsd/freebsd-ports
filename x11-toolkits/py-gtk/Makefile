# New ports collection makefile for:	py-gtk
# Date created:				09/14/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	py-gtk
PORTVERSION=	0.6.6
CATEGORIES=	x11-toolkits python
MASTER_SITES=	ftp://ftp.daa.com.au/pub/james/python/ \
		ftp://ftp.gimp.org/pub/gtk/python/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/python/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/python/ \
		ftp://stef.u-picardie.fr/mirror/ftp.gimp.org/gtk/python/
DISTNAME=	gnome-python-1.0.53

MAINTAINER=	nectar@FreeBSD.org

BUILD_DEPENDS=	python1.5:${PORTSDIR}/lang/python
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12                  \
		Imlib.5:${PORTSDIR}/graphics/imlib
RUN_DEPENDS=	python1.5:${PORTSDIR}/lang/python

GTK_CONFIG=	${X11BASE}/bin/gtk12-config
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${GTK_CONFIG}
CONFIGURE_ARGS=	--with-python=python1.5
USE_LIBTOOL=	yes
PLIST_COMPLETE= ${PKGDIR}/PLIST

WRKSRC=		${WRKDIR}/${DISTNAME}/pygtk
EG_SRC_DIR=	${WRKSRC}/examples
EG_DST_DIR=	${PREFIX}/share/examples/py-gtk

.if !defined(NOPORTDOCS)
PLIST=		${PLIST_COMPLETE}
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
		${PLIST_COMPLETE} > ${PLIST}
.endif

.include <bsd.port.mk>
