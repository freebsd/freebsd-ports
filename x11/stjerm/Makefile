# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	stjerm
PORTVERSION=	0.16
CATEGORIES=	x11
MASTER_SITES=	http://stjerm-terminal.googlecode.com/files/

MAINTAINER=	lichray@gmail.com
COMMENT=	GTK+-based quake-like terminal emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
LIBS+=		-L${LOCALBASE}/lib -lXinerama
USES=		gmake pkgconfig
USE_AUTOTOOLS=	aclocal autoheader automake
AUTOMAKE_ARGS=	--add-missing
USE_GNOME=	vte gtk20
USE_XORG=	xinerama

PLIST_FILES=	bin/stjerm man/man8/${PORTNAME}.8.gz

.include <bsd.port.mk>
