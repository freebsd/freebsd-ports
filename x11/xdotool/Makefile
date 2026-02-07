PORTNAME=	xdotool
DISTVERSION=	3.20211022.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11
MASTER_SITES=	https://github.com/jordansissel/xdotool/releases/download/v${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Programmatically simulate keyboard input or mouse activity
WWW=		https://www.semicomplete.com/projects/xdotool/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		gmake perl5 pkgconfig xorg
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XORG=	x11 xi xinerama xtst

MAKE_ARGS=	INSTALLMAN=$(PREFIX)/share/man

PLIST_FILES=	bin/xdotool \
		include/xdo.h \
		lib/libxdo.so \
		lib/libxdo.so.3 \
		libdata/pkgconfig/libxdo.pc \
		share/man/man1/xdotool.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xdotool \
		${STAGEDIR}${PREFIX}/lib/libxdo.so.3

.include <bsd.port.mk>
