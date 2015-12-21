# Created by: Evgeni Dimitrov <evgeni.dimitrov@gmail.com>
# $FreeBSD$

PORTNAME=	lemonbar
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
CATEGORIES=	x11

MAINTAINER=	evgeni.dimitrov@gmail.com
COMMENT=	Lightweight xcb based bar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake perl5
USE_PERL5=	build
USE_XORG=	xcb

USE_GITHUB=	yes
GH_ACCOUNT=	LemonBoy
GH_PROJECT=	bar

CFLAGS+=	-I${LOCALBASE}/include -DVERSION=${DISTVERSION}
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/lemonbar \
		man/man1/lemonbar.1.gz

post-patch:
	${REINPLACE_CMD} -e '/STRIP/d' -e '/^CC.*=/d' -e '/^CFLAGS.*=/d' \
		-e 's/^LDFLAGS.*=\(.*\)/LDFLAGS+=\1/' ${WRKSRC}/Makefile

post-build:
	${LOCALBASE}/bin/pod2man --section=1 --name=bar-aint-recursive \
		--center="bar-aint-recursive manual" \
		--release="bar-aint-recursive ${PORTVERSION}" \
		${WRKSRC}/README.pod > ${WRKSRC}/bar.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lemonbar ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bar.1 \
		${STAGEDIR}${PREFIX}/man/man1/lemonbar.1

.include <bsd.port.mk>
