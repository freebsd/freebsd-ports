PORTNAME=	sddm
PORTVERSION=	0.21.0
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QML based login manager
WWW=		https://github.com/sddm/sddm

# The source code is GPLv2+, but the provided themes are:
#  - CC-BY 3.0 (default greeter theme, maldives)
#  - CC-BY 4.0 (maya)
#  - Apache20 (font included with maya)
LICENSE=	GPLv2+ CC-BY-3.0 CC-BY-4.0 APACHE20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSE
LICENSE_FILE_CC-BY-3.0=	${WRKSRC}/LICENSE.CC-BY-3.0

BUILD_DEPENDS=	rst2man:textproc/py-docutils@${PY_FLAVOR}
RUN_DEPENDS=	consolekit2>1.2.5:sysutils/consolekit2 \
		dbus-launch:devel/dbus \
		xauth:x11/xauth \
		xmessage:x11/xmessage

USES=		cmake compiler:c++17-lang cpe pkgconfig python:build qt:5 xorg
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
USE_QT=		core declarative dbus gui network \
		buildtools:build linguisttools:build declarative-test:build \
		qmake:build testlib:build
USE_XORG=	xau xcb

CONFLICTS_INSTALL=	lightdm

CMAKE_ON=	BUILD_MAN_PAGES
CMAKE_ARGS=	-DUID_MIN=1000 \
		-DUID_MAX=65000 \
		-DCMAKE_INSTALL_SYSCONFDIR:PATH=${LOCALBASE}/etc \
		-DACCOUNTSSERVICE_DATA_DIR:PATH=/var/db/AccountsService \
		-DRST2MAN_EXECUTABLE=${LOCALBASE}/bin/rst2man \
		-DSDDM_INITIAL_VT=7

USE_RC_SUBR=	sddm
SUB_FILES=	xinit-session \
		xinitrc.desktop

USERS=		sddm
GROUPS=		sddm

post-patch:
	@${REINPLACE_CMD} -e 's#/etc/X11#${LOCALBASE}/etc/X11#' \
		-e 's#/usr/bin/#${LOCALBASE}/bin/#g' \
		-e 's#/usr/share/#${LOCALBASE}/share/#' \
		-e 's#%%LOCALBASE%%#${LOCALBASE}#g' \
		${WRKSRC}/data/scripts/Xsession \
		${WRKSRC}/src/common/Configuration.h \
		${WRKSRC}/src/greeter/waylandkeyboardbackend.cpp

post-install:
# Install xsession.desktop to launch .xinitrc via sddm.
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_DATA} ${FILESDIR}/sddm.conf.default ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKDIR}/xinitrc.desktop ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_SCRIPT} ${WRKDIR}/xinit-session ${STAGEDIR}${PREFIX}/share/sddm/scripts
	${MV} ${STAGEDIR}${PREFIX}/etc/pam.d/sddm ${STAGEDIR}${PREFIX}/etc/pam.d/sddm.default
	${MV} ${STAGEDIR}${PREFIX}/etc/pam.d/sddm-autologin ${STAGEDIR}${PREFIX}/etc/pam.d/sddm-autologin.default
	${MV} ${STAGEDIR}${PREFIX}/etc/pam.d/sddm-greeter ${STAGEDIR}${PREFIX}/etc/pam.d/sddm-greeter.default

.include <bsd.port.mk>
