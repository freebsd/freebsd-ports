# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cool-retro-term
PORTVERSION=	1.1.1
CATEGORIES=	x11

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Terminal emulator which mimics the old cathode display

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	Swordfish90
GH_PROJECT=	qmltermwidget:qtw
GH_TAGNAME=	0.2.0:qtw

USES=		gmake gl qmake qt:5
USE_GL=		gl
USE_QT=		qmake_build buildtools_build core declarative gui \
		network sql widgets graphicaleffects_run \
		quickcontrols_run sql-sqlite3_run

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
	@${LN} -s ../qmltermwidget-0.2.0 ${WRKSRC}/qmltermwidget

post-patch:
	@${REINPLACE_CMD} -e '/DEFINES +=/s,^macx:,,' \
		${WRKSRC}/qmltermwidget/qmltermwidget.pro
	@${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},' \
		${WRKSRC}/app/app.pro ${WRKSRC}/cool-retro-term.pro
	@${REINPLACE_CMD} -e 's,\.\./icons,/icons,' \
		${WRKSRC}/app/main.cpp

post-install:
	${INSTALL_MAN} ${WRKSRC}/packaging/debian/cool-retro-term.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
