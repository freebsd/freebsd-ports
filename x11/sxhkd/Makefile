PORTNAME=	sxhkd
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	o.hushchenkov@gmail.com
COMMENT=	Simple X hotkey daemon
WWW=		https://github.com/baskerville/sxhkd

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-keysyms.so:x11/xcb-util-keysyms

USES=		gmake localbase:ldflags xorg

USE_XORG=	xcb

USE_GITHUB=	yes
GH_ACCOUNT=	baskerville

PORTEXAMPLES=	*
PLIST_FILES=	bin/sxhkd \
		share/man/man1/sxhkd.1.gz

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
