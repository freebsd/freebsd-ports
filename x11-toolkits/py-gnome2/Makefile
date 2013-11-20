# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/py-gnome2/Makefile,v 1.60 2010/04/02 20:22:15 kwm Exp $

PORTNAME=	gnome
PORTVERSION=	2.28.1
PORTREVISION=	3
CATEGORIES=	x11-toolkits python gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gnome-python/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gnome-python-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of Python bindings for GNOME 2

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/ORBit.so:${PORTSDIR}/devel/py-orbit
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ORBit.so:${PORTSDIR}/devel/py-orbit

LATEST_LINK=	py-gnome2
USE_BZIP2=	yes
USE_PYTHON=	-2.7
USE_LDCONFIG=	yes
USES=		gettext gmake pkgconfig
USE_GNOME=	gnomehack libgnomeui pygtk2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include

EG_SRC_DIR=	${WRKSRC}/examples
EG_DST_DIR=	${PREFIX}/share/examples/py-gnome

CONFLICTS=	py*-gnome-1*

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EG_DST_DIR}
	${TAR} -C ${EG_SRC_DIR} -cf - . | ${TAR} -C ${EG_DST_DIR} -xf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EG_DST_DIR}
	${FIND} ${EG_DST_DIR} -type d -print | ${XARGS} ${CHMOD} 0755
	${FIND} ${EG_DST_DIR} -type f -print | ${XARGS} ${CHMOD} 0444
.endif

.include <bsd.port.post.mk>
