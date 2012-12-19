# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	deforaos-panel
PORTVERSION=	0.2.15
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3706/
DISTNAME=	Panel-${PORTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop panel

LICENSE=	GPLv3

LIB_DEPENDS=	System:${PORTSDIR}/devel/deforaos-libsystem \
		Desktop:${PORTSDIR}/x11/deforaos-libdesktop
BUILD_DEPENDS=	browser:${PORTSDIR}/x11-fm/deforaos-browser \
		${LOCALBASE}/include/Desktop/Keyboard.h:${PORTSDIR}/x11/deforaos-keyboard \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
RUN_DEPENDS=	keyboard:${PORTSDIR}/x11/deforaos-keyboard \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme \
		sudo:${PORTSDIR}/security/sudo

USE_GNOME=	gtk20 desktopfileutils
USE_PKGCONFIG=	build
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

MAKE_ENV+=	MANDIR=${MANPREFIX}/man

MAN1=	panel-embed.1 \
	panel-message.1 \
	panel-notify.1 \
	panel.1 \
	panelctl.1

post-patch:
	${REINPLACE_CMD} -e 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		${WRKSRC}/src/panel.c

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
