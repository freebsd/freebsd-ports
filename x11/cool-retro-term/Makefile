# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cool-retro-term
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Terminal emulator which mimics old cathode displays

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	Swordfish90
GH_PROJECT=	qmltermwidget:qtw
GH_TAGNAME=	0.2.0:qtw
GH_SUBDIR=	${GH_PROJECT}

USES=		compiler:c++11-lang gl gmake qmake qt:5
USE_GL=		gl
USE_QT=		qmake_build buildtools_build core declarative gui \
		network sql widgets graphicaleffects_run \
		quickcontrols_run sql-sqlite3_run

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

.include <bsd.port.mk>
