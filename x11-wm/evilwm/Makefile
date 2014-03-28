# Created by: trevor
# $FreeBSD$

PORTNAME=	evilwm
PORTVERSION=	1.1.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.6809.org.uk/evilwm/

MAINTAINER=	lasg@lasg.dk
COMMENT=	Minimalist window manager based on 9wm

USES=		gmake
USE_XORG=	x11 xpm xext xrandr xrender
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		evilwm.1
PORTDOCS=	ChangeLog README TODO
PLIST_FILES=	bin/evilwm \
		${DESKTOPDIR:S,^${PREFIX}/,,}/${PORTNAME}.desktop
PLIST_DIRSTRY=	${DESKTOPDIR:S,^${PREFIX}/,,}

# X11's include and library path
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
	${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${DESKTOPDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
