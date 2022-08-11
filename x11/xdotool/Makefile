PORTNAME=	xdotool
DISTVERSION=	3.20211022.1
PORTEPOCH=	1
CATEGORIES=	x11
MASTER_SITES=	https://github.com/jordansissel/xdotool/releases/download/v${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Programmatically simulate keyboard input or mouse activity

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		gmake perl5 pkgconfig xorg

USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XORG=	x11 xi xinerama xtst

PLIST_FILES=	bin/xdotool \
		include/xdo.h \
		lib/libxdo.so \
		lib/libxdo.so.3 \
		libdata/pkgconfig/libxdo.pc \
		man/man1/xdotool.1.gz

# Older GCC on RELENG_6 doesn't like -Wno-missing-field-initializers
#post-patch:
#	@${REINPLACE_CMD} -e 's,-Wno-missing-field-initializers,,' \
#		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xdotool \
		${STAGEDIR}${PREFIX}/lib/libxdo.so.3

.include <bsd.port.mk>
