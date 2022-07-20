PORTNAME=	lemonbar
DISTVERSIONPREFIX=v
DISTVERSION=	1.4
CATEGORIES=	x11

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Lightweight xcb based bar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 gmake localbase:ldflags perl5 xorg

USE_GITHUB=	yes
GH_ACCOUNT=	LemonBoy
GH_PROJECT=	bar

USE_PERL5=	build
USE_XORG=	xcb
CFLAGS+=	-D__BSD_VISIBLE # for memrchr(3)

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
