# New ports collection makefile for:	py-gnome-desktop
# Date created:				20 January 2006
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/py-gnome-desktop/Makefile,v 1.103 2010/09/30 06:27:40 kwm Exp $
#

PORTNAME=	gnome-desktop
PORTVERSION=	2.32.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits python gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gnome-python-desktop/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gnome-python-desktop-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of Python bindings used by modules in the GNOME Desktop

BUILD_DEPENDS=	bug-buddy:${PORTSDIR}/devel/bug-buddy
LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop \
		totem-plparser.17:${PORTSDIR}/multimedia/totem-pl-parser \
		gnome-media-profiles.0:${PORTSDIR}/audio/gnome-media \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring \
		brasero-media.3:${PORTSDIR}/sysutils/brasero \
		evdocument.3:${PORTSDIR}/graphics/evince
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
	@${REINPLACE_CMD} -e 's|2.30|2.32|g' ${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EG_DST_DIR}
	${TAR} -C ${EG_SRC_DIR} --exclude *nautilusburn* -cf - . | ${TAR} -C ${EG_DST_DIR} -xf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EG_DST_DIR}
	${CHMOD} -R go-w ${EG_DST_DIR}
.endif

.include <bsd.port.post.mk>
