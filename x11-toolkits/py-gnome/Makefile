# New ports collection makefile for:	py-gnome
# Version required:			1.0.1
# Date created:				3/14/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	gnome-python-1.0.50
PKGNAME=	py-gnome-1.0.50
CATEGORIES=	x11-toolkits python gnome
MASTER_SITES=	ftp://ftp.daa.com.au/pub/james/python/ \
		ftp://ftp.gimp.org/pub/gtk/python/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/python/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/python/ \
		ftp://stef.u-picardie.fr/mirror/ftp.gimp.org/gtk/python/

MAINTAINER=	nectar@FreeBSD.org

BUILD_DEPENDS=	python1.5:${PORTSDIR}/lang/python ${PYGTK_DEP}
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12                  \
		capplet.1:${PORTSDIR}/sysutils/gnomecontrolcenter
RUN_DEPENDS=	python1.5:${PORTSDIR}/lang/python ${PYGTK_DEP}

GTK_CONFIG=	${X11BASE}/bin/gtk12-config
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${GTK_CONFIG}
CONFIGURE_ARGS=	--with-python=python1.5                                 \
		--with-gnome-config=${X11BASE}/bin/gnome-config

EG_SRC_DIR=	${WRKSRC}/pygnome/examples
EG_DST_DIR=	${PREFIX}/share/examples/py-gnome
PYGTK_DEP=	${LOCALBASE}/lib/python1.5/site-packages/_gtkmodule.so:${PORTSDIR}/x11-toolkits/py-gtk
PLIST_COMPLETE= ${PKGDIR}/PLIST

.if !defined(NOPORTDOCS)
PLIST=		${PLIST_COMPLETE}
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
		${PLIST_COMPLETE} > ${PLIST}
.endif

.include <bsd.port.mk>
