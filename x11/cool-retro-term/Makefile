# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cool-retro-term
PORTVERSION=	1.0.0
PORTREVISION=	6
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Terminal emulator which mimics the old cathode display

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	Swordfish90
GH_PROJECT=	qmltermwidget:qtw
GH_TAGNAME=	v0.1.0:qtw

USES=		gmake desktop-file-utils qmake qt:5
USE_QT=		qmake_build buildtools_build core declarative gui widgets \
		graphicaleffects_run quickcontrols_run

.include <bsd.port.pre.mk>

.if ${ARCH:Mmips*} || ${ARCH:Mpowerpc*} || ${ARCH} == sparc64
USE_GCC=	yes
.else
CC=		clang
CXX=		clang++
CPP=		clang-cpp
.endif

post-extract:
	@${RMDIR} ${WRKSRC}/qmltermwidget
	@${LN} -s ../qmltermwidget-0.1.0 ${WRKSRC}/qmltermwidget

post-patch:
	@${REINPLACE_CMD} -e '/DEFINES +=/s,^macx:,,' \
		${WRKSRC}/qmltermwidget/qmltermwidget.pro
	@${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},' \
		${WRKSRC}/app/app.pro ${WRKSRC}/cool-retro-term.pro
	@${REINPLACE_CMD} -e 's,\.\./icons,/icons,' \
		${WRKSRC}/app/main.cpp

.include <bsd.port.post.mk>
