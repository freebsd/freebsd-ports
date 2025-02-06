PORTNAME=	shared-desktop-ontologies
PORTVERSION=	0.11.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/oscaf/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Interoperability between desktops and collaborative environments
WWW=		https://oscaf.sourceforge.net

DEPRECATED=	Abandonedware, not used by KDE for a long time
EXPIRATION_DATE=	2025-03-31

CMAKE_ARGS+=	-DPKGCONFIG_INSTALL_DIR:PATH="libdata/pkgconfig/"
INSTALL_TARGET=	install

USES=		cmake pkgconfig tar:bzip2

post-patch:
	@${REINPLACE_CMD} -e 's|share/cmake/SharedDesktopOntologies|lib/cmake/SharedDesktopOntologies|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
