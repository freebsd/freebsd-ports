# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	stjerm
PORTVERSION=	0.18
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	lichray@gmail.com
COMMENT=	GTK+-based quake-like terminal emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes

GNU_CONFIGURE=	yes
LIBS+=		-L${LOCALBASE}/lib -lXinerama
USES=		autoreconf gmake gnome pkgconfig xorg
USE_GNOME=	vte gtk20
USE_XORG=	xinerama

PLIST_FILES=	bin/stjerm man/man8/${PORTNAME}.8.gz

.include <bsd.port.mk>
