# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deforaos-panel
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/4338/
DISTNAME=	Panel-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS desktop panel

LICENSE=	GPLv3

BROKEN=		fails to build

LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem \
		libDesktop.so:x11/deforaos-libdesktop
BUILD_DEPENDS=	browser:x11-fm/deforaos-browser \
		${LOCALBASE}/include/Desktop/Keyboard.h:x11/deforaos-keyboard \
		${LOCALBASE}/include/Desktop/Player.h:multimedia/deforaos-player \
		xsltproc:textproc/libxslt \
		docbook-xsl>=0:textproc/docbook-xsl
RUN_DEPENDS=	keyboard:x11/deforaos-keyboard \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:misc/gnome-icon-theme \
		sudo:security/sudo

USE_GNOME=	gtk20
USES=		gettext pkgconfig
INSTALLS_ICONS=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}
USE_LDCONFIG=	yes

MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

post-patch:
	${REINPLACE_CMD} -e 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		${WRKSRC}/src/panel.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/* \
		${STAGEDIR}${PREFIX}/lib/libPanel.so.0.0

.include <bsd.port.mk>
