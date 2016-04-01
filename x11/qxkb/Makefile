# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qxkb
PORTVERSION=	0.4.6
CATEGORIES=	x11
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt4-based advanced keyboard layout switcher

LICENSE=	GPLv2+

LIB_DEPENDS=	libxkbfile.so:x11/libxkbfile

USES=		cmake tar:bzip2
USE_QT4=	linguisttools_build moc_build qmake_build rcc_build uic_build \
		corelib gui svg

LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
# Fix path to the translation files
	@${REINPLACE_CMD} -e 's,\.\./,,' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
