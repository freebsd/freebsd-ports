# $FreeBSD$

PORTNAME=	sddm
PORTVERSION=	0.18.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QML based login manager

# The source code is GPLv2+, but the provided themes are:
#  - CC-BY 3.0 (default greeter theme, maldives)
#  - CC-BY 4.0 (maya)
#  - Apache20 (font included with maya)
LICENSE=	GPLv2+ CC-BY-3.0 CC-BY-4.0 APACHE20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSE
LICENSE_FILE_CC-BY-3.0=	${WRKSRC}/LICENSE.CC-BY-3.0

BUILD_DEPENDS=	rst2man.py-${PYTHON_VER}:textproc/py-docutils@${PY_FLAVOR}
RUN_DEPENDS=	dbus-run-session:devel/dbus

USES=		cmake compiler:c++11-lang kde:5 pkgconfig python:build qt:5 xorg
USE_GITHUB=	yes
USE_KDE=	ecm
USE_QT=		core declarative dbus gui network \
		buildtools_build linguisttools_build qmake_build
USE_XORG=	xcb

CMAKE_ARGS=	-DUID_MIN=1000 \
		-DUID_MAX=65000 \
		-DCMAKE_INSTALL_SYSCONFDIR:PATH=${LOCALBASE}/etc \
		-DBUILD_MAN_PAGES=ON \
		-DRST2MAN_EXECUTABLE=${LOCALBASE}/bin/rst2man.py-${PYTHON_VER}

USE_RC_SUBR=	sddm
SUB_FILES=	xinitrc.desktop

USERS=		sddm
GROUPS=		sddm

post-patch:
	@${REINPLACE_CMD} -e 's#/etc/X11#${LOCALBASE}/etc/X11#' \
		-e 's#/usr/bin/#${LOCALBASE}/bin/#g' \
		-e 's#/usr/share/#${LOCALBASE}/share/#' \
		${WRKSRC}/data/scripts/Xsession \
		${WRKSRC}/src/common/Configuration.h
	@${CP} ${PATCHDIR}/VirtualTerminal_FreeBSD.cpp ${WRKSRC}/src/daemon

post-install:
# Install xsession.desktop to launch .xinitrc via sddm.
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_DATA} ${WRKDIR}/xinitrc.desktop ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_SCRIPT} ${FILESDIR}/xinit-session ${STAGEDIR}${PREFIX}/share/sddm/scripts

.include <bsd.port.mk>
