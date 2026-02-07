PORTNAME=	lxqt
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Meta-port for the LXQt Desktop
WWW=		https://lxqt-project.org

RUN_DEPENDS=	startlxqt:x11-wm/lxqt-session \
	lxqt-about>=${PORTVERSION}:x11/lxqt-about \
	lxqt-admin>=${PORTVERSION}:sysutils/lxqt-admin \
	lxqt-config>=${PORTVERSION}:sysutils/lxqt-config \
	lxqt-qtplugin>=1.4.0:sysutils/lxqt-qtplugin \
	lxqt-qt6plugin>=${PORTVERSION}:sysutils/lxqt-qt6plugin \
	qterminal>=2.3.0:x11/qterminal \
	obconf-qt>=0.16.6:x11-wm/obconf-qt \
	lximage-qt>=${PORTVERSION}:graphics/lximage-qt \
	lxqt-runner>=${PORTVERSION}:x11/lxqt-runner \
	lxqt-powermanagement>=${PORTVERSION}:sysutils/lxqt-powermanagement \
	${PREFIX}/share/lxqt/themes/frost/lxqt-panel.qss:x11-themes/lxqt-themes \
	pcmanfm-qt>=${PORTVERSION}:x11-fm/pcmanfm-qt \
	screengrab>=3.1.0:x11/screengrab \
	lxqt-archiver>=1.3.0:archivers/lxqt-archiver \
	lxqt-notificationd>=${PORTVERSION}:deskutils/lxqt-notificationd \
	lxqt-panel>=${PORTVERSION}:x11-wm/lxqt-panel \
	lxqt-policykit>=${PORTVERSION}:sysutils/lxqt-policykit \
	lxqt-wayland-session>=0.3.0:x11-wm/lxqt-wayland-session \
	qlipper:deskutils/qlipper \
	openbox:x11-wm/openbox \
	xdg-desktop-portal-lxqt>0:deskutils/xdg-desktop-portal-lxqt \
	qtxdg-tools>0:sysutils/qtxdg-tools

USES=	qt:6 metaport
USE_QT=	translations

OPTIONS_DEFINE=		EDITOR SSH SUDO
OPTIONS_DEFAULT=	EDITOR SSH SUDO

EDITOR_DESC=		Install plain-text editor
SSH_DESC=		GUI passphrase entry dialog for ssh-agent
SUDO_DESC=		GUI frontend (Qt6) to sudo/su

EDITOR_RUN_DEPENDS=	featherpad:editors/featherpad
SSH_RUN_DEPENDS=	lxqt-openssh-askpass:security/lxqt-openssh-askpass
SUDO_RUN_DEPENDS=	lxqt-sudo:security/lxqt-sudo

.include <bsd.port.mk>
