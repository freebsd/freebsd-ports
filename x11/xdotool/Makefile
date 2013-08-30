# $FreeBSD$

PORTNAME=	xdotool
DISTVERSION=	2.20110530.1
PORTEPOCH=	1
CATEGORIES=	x11
MASTER_SITES=	http://semicomplete.googlecode.com/files/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Programmatically simulate keyboard input or mouse activity

USE_PERL5_BUILD=	yes
USE_LDCONFIG=	yes
USES=		gmake pkgconfig
USE_XORG=	x11 xtst xinerama

MAN1=		xdotool.1
PLIST_FILES=	bin/xdotool lib/libxdo.so lib/libxdo.so.2 include/xdo.h

# Older GCC on RELENG_6 doesn't like -Wno-missing-field-initializers
post-patch:
	@${REINPLACE_CMD} -e 's,-Wno-missing-field-initializers,,' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
