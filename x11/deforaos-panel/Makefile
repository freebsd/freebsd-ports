# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	deforaos-panel
PORTVERSION=	0.2.18
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/4295/
DISTNAME=	Panel-${PORTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop panel

LICENSE=	GPLv3

LIB_DEPENDS=	libSystem.so:${PORTSDIR}/devel/deforaos-libsystem \
		libDesktop.so:${PORTSDIR}/x11/deforaos-libdesktop
BUILD_DEPENDS=	browser:${PORTSDIR}/x11-fm/deforaos-browser \
		${LOCALBASE}/include/Desktop/Keyboard.h:${PORTSDIR}/x11/deforaos-keyboard \
		${LOCALBASE}/include/Desktop/Player.h:${PORTSDIR}/multimedia/deforaos-player \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
RUN_DEPENDS=	keyboard:${PORTSDIR}/x11/deforaos-keyboard \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme \
		sudo:${PORTSDIR}/security/sudo

USE_GNOME=	gtk20
USES=		desktop-file-utils gettext pkgconfig
INSTALLS_ICONS=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}

MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

post-patch:
	${REINPLACE_CMD} -e 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		${WRKSRC}/src/panel.c

.include <bsd.port.mk>
