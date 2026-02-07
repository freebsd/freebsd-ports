PORTNAME=	grabc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Grab a color from screen
WWW=		https://www.muquit.com/muquit/software/grabc/grabc.html

LICENSE=	MIT

USES=		localbase xorg
USE_GITHUB=	yes
GH_ACCOUNT=	muquit
USE_XORG=	x11 xorgproto

PLIST_FILES=	bin/grabc share/man/man1/grabc.1.gz

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c \
		${LIBS} -lX11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
