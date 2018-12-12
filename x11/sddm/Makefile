# $FreeBSD$

PORTNAME=	sddm
PORTVERSION=	0.17.0
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	x11

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QML based login manager

# The source code is GPLv2+, but the provided themes are:
#  - CC-BY 3.0 (default greeter theme, maldives)
#  - CC-BY 4.0 (maya)
#  - Apache20 (font included with maya)
LICENSE=	GPLv2+ CC-BY-3.0 CC-BY-4.0 APACHE20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+=	${WRKSRC}/LICENSE
LICENSE_FILE_CC-BY-3.0=	${WRKSRC}/LICENSE.CC-BY-3.0

RUN_DEPENDS=	dbus-run-session:devel/dbus

USES=		cmake:outsource compiler:c++11-lang kde:5 qt:5
USE_GITHUB=	yes
USE_KDE=	ecm
USE_QT=		core declarative dbus gui network \
		buildtools_build linguisttools_build qmake_build
USE_XORG=	xcb

CMAKE_ARGS=	-DUID_MIN=1000 \
		-DUID_MAX=65000 \
		-DCMAKE_INSTALL_SYSCONFDIR:PATH=${LOCALBASE}/etc

USE_RC_SUBR=	sddm
SUB_FILES=	xinitrc.desktop

USERS=		sddm
GROUPS=		sddm

# There are multiple patches that apply to Display.cpp,
# fixing CVE-2018-14345 and backported from 0.18.
EXTRA_PATCHES=	${PATCHDIR}/git-patch-147cec38d ${PATCHDIR}/git-patch-b02b00559

post-patch:
	@${REINPLACE_CMD} -e 's#/etc/X11#${LOCALBASE}/etc/X11#' \
		-e 's#/usr/bin/#${LOCALBASE}/bin/#g' \
		-e 's#/usr/share/#${LOCALBASE}/share/#' \
		${WRKSRC}/data/scripts/Xsession \
		${WRKSRC}/src/common/Configuration.h

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/sddm.conf \
		${STAGEDIR}${PREFIX}/etc/sddm.conf.sample
# Install xsession.desktop to launch .xinitrc via sddm.
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_DATA} ${WRKDIR}/xinitrc.desktop ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_SCRIPT} ${FILESDIR}/xinit-session ${STAGEDIR}${PREFIX}/share/sddm/scripts

.include <bsd.port.mk>
