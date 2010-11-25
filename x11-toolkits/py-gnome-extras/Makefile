# New ports collection makefile for:	py-gnome-extras
# Date created:				22 November 2005
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/py-gnome-extras/Makefile,v 1.55 2009/11/28 05:59:04 mezz Exp $
#

PORTNAME=	gnome-extras
PORTVERSION=	2.25.3
PORTREVISION=	10
CATEGORIES=	x11-toolkits python gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gnome-python-extras/${PORTVERSION:C/..$//}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gnome-python-extras-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of Python bindings for GNOME 2

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell \
		gksu1.2.0:${PORTSDIR}/sysutils/libgksu \
		gksuui1.0.1:${PORTSDIR}/sysutils/libgksuui
#		gdl-1.2:${PORTSDIR}/x11-toolkits/gdl

USE_GECKO=	libxul
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack libgtkhtml pygnome2 libgda4
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--disable-gdl

EG_SRC_DIR=	${WRKSRC}/examples
EG_DST_DIR=	${PREFIX}/share/examples/py-gnome
.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/py-gnome-extras
.else
DOCSDIR=	${WRKSRC}/share/doc/py-gnome-extras
.endif

.include <bsd.port.pre.mk>

.if defined(GECKO)
CONFIGURE_ARGS+=	--with-gtkmozembed=${GECKO}
.endif

post-patch:
.if ${GECKO}=="libxul"
	@${REINPLACE_CMD} -e 's|xulrunner|libxul|' \
		${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|$mozpackage-gtkmozembed|$mozpackage|' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC}/docs -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^HTML_DIR =.*|HTML_DIR = ${DOCSDIR}|g'

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EG_DST_DIR}
	${TAR} -C ${EG_SRC_DIR} -cf - . | ${TAR} -C ${EG_DST_DIR} -xf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EG_DST_DIR}
	${CHMOD} -R go-w ${EG_DST_DIR}
.endif

.include <bsd.port.post.mk>
