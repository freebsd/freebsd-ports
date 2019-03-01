# Created by: Anton Tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	sxhkd
PORTVERSION=	0.6.0
CATEGORIES=	x11

MAINTAINER=	o.hushchenkov@gmail.com
COMMENT=	Simple X hotkey daemon

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-keysyms.so:x11/xcb-util-keysyms

USES=		gmake localbase:ldflags

USE_XORG=	xcb

USE_GITHUB=	yes
GH_ACCOUNT=	baskerville

PORTEXAMPLES=	*
PLIST_FILES=	bin/sxhkd \
		man/man1/sxhkd.1.gz

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${MKDIR} ${STAGEDIR}${BINDIR} ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
