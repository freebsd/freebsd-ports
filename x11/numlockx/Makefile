PORTNAME=	numlockx
PORTVERSION=	1.2
CATEGORIES=	x11
MASTER_SITES=	https://mirror.amdmi3.ru/distfiles/ \
		LOCAL/ehaupt

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Turns on numlock in X
WWW=		http://home.kde.org/~seli/numlockx/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase xorg
USE_XORG=	x11 xext xtst
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

PLIST_FILES=	bin/numlockx

.include <bsd.port.mk>
