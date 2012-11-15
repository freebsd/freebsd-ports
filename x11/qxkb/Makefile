# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qxkb
PORTVERSION=	0.4.4
CATEGORIES=	x11
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Qt4-based advanced keyboard layout switcher

LICENSE=	GPLv3

LIB_DEPENDS=	xkbfile:${PORTSDIR}/x11/libxkbfile

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT4=	qmake_build moc_build rcc_build uic_build corelib gui svg

LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
