PORTNAME=	sddm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.0-36
DISTVERSIONSUFFIX=	-gc2b97dd
PORTREVISION=	2
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
LICENSE_FILE_CC-BY-3.0=	${WRKSRC}/LICENSE.CC-BY-3.0
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rst2man:textproc/py-docutils@${PY_FLAVOR}
RUN_DEPENDS=	consolekit2>1.2.5:sysutils/consolekit2 \
		dbus-launch:devel/dbus \
		xauth:x11/xauth \
		xmessage:x11/xmessage \
		xrdb:x11/xrdb \
		xsetroot:x11/xsetroot

USES=		cmake compiler:c++17-lang cpe gl pkgconfig python:build qt:6 xorg
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
USE_GL=		gl opengl # GLX
USE_QT=		base declarative \
		tools:build
USE_RC_SUBR=	sddm
USE_XORG=	xau xcb

CMAKE_ARGS=	-DACCOUNTSSERVICE_DATA_DIR:PATH=/var/db/AccountsService \
		-DCMAKE_INSTALL_SYSCONFDIR:PATH=${LOCALBASE}/etc \
		-DRST2MAN_EXECUTABLE=${LOCALBASE}/bin/rst2man \
		-DSDDM_INITIAL_VT=7 \
		-DUID_MIN=1000 \
		-DUID_MAX=65000
CMAKE_ON=	BUILD_MAN_PAGES \
		BUILD_WITH_QT6

CONFLICTS_INSTALL=	lightdm

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
# Install our own PAM configs. Upstream is no longer providing these for any
# platform and now just leaves this part to downstream packagers.
# https://github.com/sddm/sddm/commit/b82f9be9cbd25e734958ad5eb3465579befcd0c0
# https://github.com/sddm/sddm/commit/ae072f901671b68861da9577e3e12e350a9053d5
	${CP} ${FILESDIR}/sddm.default ${STAGEDIR}${PREFIX}/etc/pam.d
	${CP} ${FILESDIR}/sddm-autologin.default ${STAGEDIR}${PREFIX}/etc/pam.d
	${CP} ${FILESDIR}/sddm-greeter.default ${STAGEDIR}${PREFIX}/etc/pam.d

.include <bsd.port.mk>
