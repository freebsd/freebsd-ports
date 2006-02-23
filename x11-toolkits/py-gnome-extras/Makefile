# New ports collection makefile for:	py-gnome-extras
# Date created:				22 November 2005
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-toolkits/py-gnome-extras/Makefile,v 1.26 2005/11/29 16:07:33 marcus Exp $
#

PORTNAME=	gnome
PORTVERSION=	2.12.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits python gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-python-extras/${PORTVERSION:C/..$//}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-extras
DISTNAME=	gnome-python-extras-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of Python bindings for GNOME 2

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2 \
		gtop-2.0.2:${PORTSDIR}/devel/libgtop2 \
		totem-plparser.1:${PORTSDIR}/multimedia/totem-gstreamer \
		gksu1.2.0:${PORTSDIR}/sysutils/libgksu \
		gksuui1.0.1:${PORTSDIR}/sysutils/libgksuui \
		gnome-media-profiles.0:${PORTSDIR}/audio/gnomemedia2 \
		gdl-1.0:${PORTSDIR}/x11-toolkits/gdl

USE_GECKO=	firefox mozilla seamonkey
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack libgnomeprintui libgtkhtml gnomepanel \
		gtksourceview libwnck nautiluscdburner pygnome2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtkmozembed=${GECKO}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

EG_SRC_DIR=	${WRKSRC}/examples
EG_DST_DIR=	${PREFIX}/share/examples/py-gnome
.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/py-gnome-extras
.else
DOCSDIR=	${WRKSRC}/share/doc/py-gnome-extras
.endif

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"

post-patch:
	@${FIND} ${WRKSRC}/docs -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^HTML_DIR =.*|HTML_DIR = ${DOCSDIR}|g'
	@${REINPLACE_CMD} -e 's|-DHAVE_GNOMEPRINT28||g' \
		${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EG_DST_DIR}
	${TAR} -C ${EG_SRC_DIR} -cf - . | ${TAR} -C ${EG_DST_DIR} -xf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EG_DST_DIR}
.endif

.include <bsd.port.post.mk>
