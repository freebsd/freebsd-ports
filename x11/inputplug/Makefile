PORTNAME=	inputplug
DISTVERSION=	0.3
CATEGORIES=	x11

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	XInput event monitor daemon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mk-configure>=0:devel/mk-configure

USES=		localbase perl5 pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	andrewshadura
USE_PERL5=	build
USE_XORG=	x11 xcb xi
MAKE_CMD=	mkcmake
MAKE_ARGS=	MANDIR="${PREFIX}/share/man"

PLIST_FILES=	bin/inputplug \
		share/man/man1/inputplug.1.gz

.include <bsd.port.mk>
