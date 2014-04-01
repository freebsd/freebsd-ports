# Created by: trevor
# $FreeBSD$

PORTNAME=	evilwm
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.6809.org.uk/evilwm/

MAINTAINER=	lasg@lasg.dk
COMMENT=	Minimalist window manager based on 9wm

USES=		gmake
USE_XORG=	x11 xpm xext xrandr xrender
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

PORTDOCS=	ChangeLog README TODO
PLIST_FILES=	bin/evilwm \
		man/man1/evilwm.1.gz \
		${DESKTOPDIR:S,^${PREFIX}/,,}/${PORTNAME}.desktop

# X11's include and library path
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/evilwm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/evilwm.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/evilwm.desktop ${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
