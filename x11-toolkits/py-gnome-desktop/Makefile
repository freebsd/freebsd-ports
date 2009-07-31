# New ports collection makefile for:	py-gnome-desktop
# Date created:				20 January 2006
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/py-gnome-desktop/Makefile,v 1.86 2009/03/15 00:39:36 marcus Exp $
#

PORTNAME=	gnome
PORTVERSION=	2.26.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits python gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gnome-python-desktop/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-desktop
DISTNAME=	gnome-python-desktop-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of Python bindings used by modules in the GNOME Desktop

BUILD_DEPENDS=	bug-buddy:${PORTSDIR}/devel/bug-buddy
LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop \
		totem-plparser.12:${PORTSDIR}/multimedia/totem-pl-parser \
		gnome-media-profiles.0:${PORTSDIR}/audio/gnome-media \
		gnome-keyring:${PORTSDIR}/security/gnome-keyring \
		evdocument.1:${PORTSDIR}/graphics/evince
RUN_DEPENDS=	bug-buddy:${PORTSDIR}/devel/bug-buddy

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack libgnomeprintui gnomepanel gnomedesktop \
		gtksourceview libwnck nautilus2 pygnome2 metacity \
		evolutiondataserver
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-metacity --disable-nautilusburn
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

EG_SRC_DIR=	${WRKSRC}/examples
EG_DST_DIR=	${PREFIX}/share/examples/py-gnome
.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/py-gnome-desktop
.else
DOCSDIR=	${WRKSRC}/share/doc/py-gnome-desktop
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${FIND} ${WRKSRC}/docs -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^HTML_DIR =.*|HTML_DIR = ${DOCSDIR}|g'

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EG_DST_DIR}
	${TAR} -C ${EG_SRC_DIR} --exclude *nautilusburn* -cf - . | ${TAR} -C ${EG_DST_DIR} -xf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EG_DST_DIR}
	${CHMOD} -R go-w ${EG_DST_DIR}
.endif

.include <bsd.port.post.mk>
