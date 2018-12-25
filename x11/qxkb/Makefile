# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qxkb
PORTVERSION=	0.4.6
DISTVERSIONPREFIX=	qxkb-
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt4-based advanced keyboard layout switcher

LICENSE=	GPLv2+

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libxkbfile.so:x11/libxkbfile

USES=		cmake:insource qt:4
USE_QT=		linguisttools_build moc_build qmake_build rcc_build uic_build \
		corelib gui svg

USE_GITHUB=	yes
GH_ACCOUNT=	disels

LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
# Fix path to the translation files
	@${REINPLACE_CMD} -e 's,\.\./,,' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
