# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qxkb
PORTVERSION=	0.4.5
CATEGORIES=	x11
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt4-based advanced keyboard layout switcher

LICENSE=	GPLv3

LIB_DEPENDS=	xkbfile:${PORTSDIR}/x11/libxkbfile

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT4=	qmake_build linguist_build moc_build rcc_build uic_build \
		corelib gui svg

LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
# Fix path to the translation files
	@${REINPLACE_CMD} -e 's,\.\./,,' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
