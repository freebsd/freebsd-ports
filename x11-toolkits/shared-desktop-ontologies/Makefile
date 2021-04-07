PORTNAME=	shared-desktop-ontologies
PORTVERSION=	0.11.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/oscaf/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Interoperability between desktops and collaborative environments

CMAKE_ARGS+=	-DPKGCONFIG_INSTALL_DIR:PATH="libdata/pkgconfig/"
INSTALL_TARGET=	install

USES=		cmake pkgconfig tar:bzip2

post-patch:
	@${REINPLACE_CMD} -e 's|share/cmake/SharedDesktopOntologies|lib/cmake/SharedDesktopOntologies|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
