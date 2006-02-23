# New ports collection makefile for:	py-gnome
# Date created:				09 February 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/py-gnome2/Makefile,v 1.24 2005/10/03 16:28:50 marcus Exp $
#

PORTNAME=	gnome
PORTVERSION=	2.12.3
PORTREVISION=	1
CATEGORIES=	x11-toolkits python gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-python/${PORTVERSION:C/..$//}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gnome-python-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of Python bindings for GNOME 2

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/ORBit.so:${PORTSDIR}/devel/py-orbit2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ORBit.so:${PORTSDIR}/devel/py-orbit2

LATEST_LINK=	py-gnome2
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack libgnomeui pygtk2
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

EG_SRC_DIR=	${WRKSRC}/examples
EG_DST_DIR=	${PREFIX}/share/examples/py-gnome

CONFLICTS=	py*-gnome-1*

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 503001
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-gnomevfs_Makefile.in
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|' \
		${WRKSRC}/gnomevfs/Makefile.in

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EG_DST_DIR}
	${TAR} -C ${EG_SRC_DIR} -cf - . | ${TAR} -C ${EG_DST_DIR} -xf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EG_DST_DIR}
	${FIND} ${EG_DST_DIR} -type d -print | ${XARGS} ${CHMOD} 0555
	${FIND} ${EG_DST_DIR} -type f -print | ${XARGS} ${CHMOD} 0444
.endif

.include <bsd.port.post.mk>
