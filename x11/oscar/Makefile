PORTNAME=	OSCAR
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.1
CATEGORIES=	x11

MAINTAINER=	sdalu@sdalu.com
COMMENT=	Open Source CPAP Analysis Reporter
WWW=		https://www.sleepfiles.com/OSCAR/

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash

USES=		gl gmake qmake:outsource qt:6 shebangfix xorg

USE_GITLAB=	yes
GL_ACCOUNT=	CrimsonNape
GL_PROJECT=	oscar-sql

USE_GL=		gl glu
USE_QT=		base serialport tools sqldriver-sqlite:run
USE_XORG=	x11

SHEBANG_FILES=	update_gitinfo.sh

REPLACE_ARGS_BASH=	-e 's,/bin/bash,${LOCALBASE}/bin/bash,'
REPLACE_ARGS_SHARE=	-e 's,/usr/share,${PREFIX}/share,'

QMAKE_ARGS+=	CONFIG+=warn_off

DATADIR=	${PREFIX}/share/OSCAR20

WRKSRC_SUBDIR=	oscar

pre-patch:
	@${REINPLACE_CMD} ${REPLACE_ARGS_BASH} ${WRKSRC}/oscar.pro
	@${REINPLACE_CMD} ${REPLACE_ARGS_SHARE} ${WRKSRC}/../Building/Linux/OSCAR20.desktop
	@${CP} ${WRKSRC}/SleepLib/thirdparty/botan_linux.h \
		${WRKSRC}/SleepLib/thirdparty/botan_freebsd.h

do-install:
	(cd ${BUILD_WRKSRC} && ${INSTALL_PROGRAM} OSCAR20 \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${BUILD_WRKSRC} && \
		${COPYTREE_SHARE} "Html Translations" ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "icons help" ${STAGEDIR}${DATADIR})

	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/../Building/Linux/OSCAR20.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/../Building/Linux/OSCAR20.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	${INSTALL_DATA} ${WRKSRC}/../Building/Linux/OSCAR20.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
