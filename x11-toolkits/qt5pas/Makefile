# $FreeBSD$

PORTNAME=	qt5pas
PORTVERSION=	2.6
CATEGORIES=	x11-toolkits
MASTER_SITES=	LOCAL/acm/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Qt5 binding for FreePascal

USE_LDCONFIG=	yes
USES=		qmake qt:5
USE_QT=		buildtools_build core gui network printsupport x11extras

QT5_VER_MIN=	5.6.1

.include <bsd.port.pre.mk>

.if ${QT5_VERSION:S/.//g} < ${QT5_VER_MIN:S/.//g}
IGNORE=		please update your current qt5 version to ${QT5_VER_MIN}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-mincoming-stack-boundary=2||g' ${WRKSRC}/Qt5Pas.pro

.include <bsd.port.post.mk>
