# New ports collection makefile for:	shared-desktop-ontologies
# Date created:		2009-11-27
# Whom:			Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	shared-desktop-ontologies
PORTVERSION=	0.5
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/oscaf/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Interoperability between desktops and collaborative environments

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GNOME=	pkgconfig

post-patch:
	@${REINPLACE_CMD} -e 's|share/pkgconfig|libdata/pkgconfig|g' \
			-e 's|shared-desktop-ontologies NONE|shared-desktop-ontologies|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
