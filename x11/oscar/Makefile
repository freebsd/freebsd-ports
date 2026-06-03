PORTNAME=	OSCAR
DISTVERSIONPREFIX=	v
DISTVERSION=    1.6.1
CATEGORIES=	x11

MAINTAINER=	sdalu@sdalu.com
COMMENT=	Open Source CPAP Analysis Reporter
WWW=		https://www.sleepfiles.com/OSCAR/

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash

USES=		gmake qmake:outsource qt:6 shebangfix xorg gl desktop-file-utils
USE_XORG=       x11
USE_GL=         gl glu
USE_QT=		base tools serialport

USE_GITLAB=     yes
GL_ACCOUNT=     CrimsonNape
GL_PROJECT=     OSCAR-code

WRKSRC_SUBDIR=  oscar

SHEBANG_FILES=  update_gitinfo.sh

REPLACE_ARGS_BASH=	-e 's,/bin/bash,${LOCALBASE}/bin/bash,'
REPLACE_ARGS_SHARE=     -e 's,/usr/share,${LOCALBASE}/share,'

QMAKE_ARGS+=	CONFIG+=warn_off

pre-patch:
	@${REINPLACE_CMD} ${REPLACE_ARGS_BASH} ${WRKSRC}/oscar.pro
	@${REINPLACE_CMD} ${REPLACE_ARGS_SHARE} ${WRKSRC}/../Building/Linux/OSCAR.desktop
	@${CP} ${WRKSRC}/SleepLib/thirdparty/botan_linux.h \
		${WRKSRC}/SleepLib/thirdparty/botan_freebsd.h

do-install:
	(cd ${BUILD_WRKSRC} && ${INSTALL_PROGRAM} OSCAR \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${BUILD_WRKSRC} && \
		${COPYTREE_SHARE} "Html Translations" ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "icons help" ${STAGEDIR}${DATADIR})

	${MKDIR} ${STAGEDIR}${LOCALBASE}/share/icons/hicolor/scalable/apps
	${MKDIR} ${STAGEDIR}${LOCALBASE}/share/icons/hicolor/48x48/apps
	${INSTALL_DATA} ${WRKSRC}/../Building/Linux/OSCAR.svg \
		${STAGEDIR}${LOCALBASE}/share/icons/hicolor/scalable/apps/OSCAR.svg
	${INSTALL_DATA} ${WRKSRC}/../Building/Linux/OSCAR.png \
		${STAGEDIR}${LOCALBASE}/share/icons/hicolor/48x48/apps/OSCAR.png
	${INSTALL_DATA} ${WRKSRC}/../Building/Linux/OSCAR.desktop \
		${STAGEDIR}${LOCALBASE}/share/applications/OSCAR.desktop

.include <bsd.port.mk>
