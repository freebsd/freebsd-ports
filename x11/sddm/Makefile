# $FreeBSD$

PORTNAME=	sddm
PORTVERSION=	0.14.0
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QML based login manager

USES=		cmake:outsource desktop-file-utils kde:5
USE_KDE=	ecm
USE_QT5=	concurrent core dbus gui linguisttools multimedia network \
		printsupport qml quick script sql webkit widgets \
		buildtools_build qmake_build
USE_XORG=	xcb

CMAKE_ARGS=	-DUID_MIN=1000 \
		-DUID_MAX=65000 \
		-DCMAKE_INSTALL_SYSCONFDIR:PATH=${LOCALBASE}/etc
# We need to disable PAM at the moment and use the passwd-based backend;
# the two backend are mutually exclusive, and we have to investigate how
# to make it compatible with OpenPAM.
CMAKE_ARGS+=	-DENABLE_PAM:BOOL=FALSE

USE_RC_SUBR=	sddm

USERS=		sddm
GROUPS=		sddm

USE_GITHUB=	yes

post-patch:
# Patch in the correct location for X11 startup files, and make the session start
# script of sddm use the value of ${STARTUP} defined by 90-consolekit
	${REINPLACE_CMD} -e 's#/etc/X11#${LOCALBASE}/etc/X11#g' \
			 -e '/exec.*session/s#exec#exec $${STARTUP}#g' \
		${PATCH_WRKSRC}/data/scripts/Xsession

post-install:
# Install xsession.desktop to launch .xinitrc via sddm.
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_DATA} ${FILESDIR}/xinitrc.desktop ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_SCRIPT} ${FILESDIR}/xinit-session ${STAGEDIR}${PREFIX}/share/sddm/scripts

.include <bsd.port.mk>
