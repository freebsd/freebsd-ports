# Created by: Evgeni Dimitrov <evgeni.dimitrov@gmail.com>
# $FreeBSD$

PORTNAME=	lemonbar
PORTVERSION=	1.2
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	x11

MAINTAINER=	evgeni.dimitrov@gmail.com
COMMENT=	Lightweight xcb based bar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 gmake perl5
USE_PERL5=	build
USE_XORG=	xcb

USE_GITHUB=	yes
GH_ACCOUNT=	LemonBoy
GH_PROJECT=	bar

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/lemonbar \
		man/man1/lemonbar.1.gz

post-patch:
	${REINPLACE_CMD} -e '/^CC.*=/d' -e '/^CFLAGS.*=/s/-Os//' \
		${WRKSRC}/Makefile

post-build:
	${LOCALBASE}/bin/pod2man --section=1 --name=lemonbar \
		--center="lemonbar manual" \
		--release="lemonbar ${PORTVERSION}" \
		${WRKSRC}/README.pod > ${WRKSRC}/lemonbar.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lemonbar ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lemonbar.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
