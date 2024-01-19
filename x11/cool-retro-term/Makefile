PORTNAME=	cool-retro-term
PORTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	x11

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Terminal emulator which mimics old cathode displays
WWW=		https://github.com/Swordfish90/cool-retro-term

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	Swordfish90
GH_PROJECT=	qmltermwidget:qtw
GH_TAGNAME=	0.2.0:qtw
GH_SUBDIR=	${GH_PROJECT}

USES=		compiler:c++11-lang gl gmake qmake qt:5
USE_GL=		gl
USE_QT=		qmake:build buildtools:build core declarative gui \
		network sql widgets graphicaleffects:run \
		quickcontrols:run sql-sqlite3:run

post-patch:
	@${REINPLACE_CMD} -e '/DEFINES +=/s,^macx:,,' \
		${WRKSRC}/qmltermwidget/qmltermwidget.pro
	@${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},' \
		${WRKSRC}/app/app.pro ${WRKSRC}/cool-retro-term.pro
	@${REINPLACE_CMD} -e 's,\.\./icons,/icons,' \
		${WRKSRC}/app/main.cpp

post-install:
	${INSTALL_MAN} ${WRKSRC}/packaging/debian/cool-retro-term.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
