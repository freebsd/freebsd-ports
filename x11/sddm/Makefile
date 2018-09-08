# $FreeBSD$

PORTNAME=	sddm
PORTVERSION=	0.17.0
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QML based login manager

RUN_DEPENDS=	dbus-run-session:devel/dbus

USES=		cmake:outsource kde:5 qt:5
USE_KDE=	ecm
USE_QT=		concurrent core dbus gui linguisttools multimedia network \
		printsupport qml quick script sql webkit widgets \
		buildtools_build qmake_build
USE_XORG=	xcb

CMAKE_ARGS=	-DUID_MIN=1000 \
		-DUID_MAX=65000 \
		-DCMAKE_INSTALL_SYSCONFDIR:PATH=${LOCALBASE}/etc

USE_RC_SUBR=	sddm
SUB_FILES=	xinitrc.desktop

USERS=		sddm
GROUPS=		sddm

USE_GITHUB=	yes

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
