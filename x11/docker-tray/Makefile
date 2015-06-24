# Created by: Samy Al Bahra <samy@kerneled.org>
# $FreeBSD$

PORTNAME=	docker-tray
PORTVERSION=	1.5
PORTREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	http://offload2.icculus.org:9090/openbox/2/docker/ \
		http://offload1.icculus.org:9090/openbox/2/docker/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp with support for GNOME2 and KDE3 tray icons

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XORG=	x11
USE_GNOME=	glib20
USES=		gmake pkgconfig

PLIST_FILES=	bin/docker

post-patch:
	@${REINPLACE_CMD} -e \
		's|^PREFIX=|PREFIX?=| ; \
		 s|^CFLAGS=|CFLAGS?=| ; \
		 s|--cflags glib-2.0|--cflags x11 glib-2.0| ; \
		 s|--libs glib-2.0|--libs x11 glib-2.0| ; \
		 s|-L$$(XLIBPATH)|| ; \
		 s|-lX11||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
