# $FreeBSD$

PORTNAME=	xdotool
DISTVERSIONPREFIX=	v
DISTVERSION=	3.20150503.1
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	gregf@hugops.pw
COMMENT=	Programmatically simulate keyboard input or mouse activity

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USE_GITHUB=	yes
GH_ACCOUNT=	jordansissel

USE_LDCONFIG=	yes
USES=		gmake pkgconfig perl5
USE_XORG=	x11 xtst xinerama
USE_PERL5=	build

# Older GCC on RELENG_6 doesn't like -Wno-missing-field-initializers
post-patch:
	@${REINPLACE_CMD} -e 's,-Wno-missing-field-initializers,,' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
