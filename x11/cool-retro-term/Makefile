# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cool-retro-term
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	x11
MASTER_SITES=	LOCAL/danfe:qtw
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		qmltermwidget-0.1.0${EXTRACT_SUFX}:qtw

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Terminal emulator which mimics the old cathode display

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	Swordfish90

USES=		desktop-file-utils qmake
USE_QT5=	qmake_build buildtools_build core gui qml quick widgets \
		graphicaleffects_run quickcontrols_run
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900014 || ${ARCH} == powerpc
USE_GCC=	yes
.else
CC=		clang
CXX=		clang++
CPP=		clang-cpp
.endif

post-extract:
	@${RMDIR} ${WRKSRC}/qmltermwidget
	@${LN} -s ${WRKDIR}/qmltermwidget-0.1.0 ${WRKSRC}/qmltermwidget

post-patch:
	@${REINPLACE_CMD} -e '/DEFINES +=/s,^macx:,,' \
		${WRKSRC}/qmltermwidget/qmltermwidget.pro
.if ${OSVERSION} < 900007
	@${REINPLACE_CMD} -e 's,HAVE_UTMPX,HAVE_UTMP,' \
		${WRKSRC}/qmltermwidget/qmltermwidget.pro
	@${REINPLACE_CMD} -e 's,ut_user,ut_name,g' \
		${WRKSRC}/qmltermwidget/lib/kpty.cpp
.else
	@${REINPLACE_CMD} -e '/define HAVE_LOGIN/d' \
		${WRKSRC}/qmltermwidget/lib/kpty.cpp
.endif
	@${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},' \
		${WRKSRC}/app/app.pro ${WRKSRC}/cool-retro-term.pro
	@${REINPLACE_CMD} -e 's,\.\./icons,/icons,' \
		${WRKSRC}/app/main.cpp

.include <bsd.port.post.mk>
