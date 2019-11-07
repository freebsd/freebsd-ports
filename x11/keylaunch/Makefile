# Created by: mwm@mired.org
# $FreeBSD$

PORTNAME=	keylaunch
PORTVERSION=	1.3.0
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://www.mired.org/downloads/

MAINTAINER=	mwm@mired.org
COMMENT=	X utility for binding commands to a hot key

BROKEN=		unfetchable

WRKSRC=		${WRKDIR}/keylaunch
USES=		perl5 gmake xorg
USE_PERL5=	build
USE_XORG=	x11

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keylaunch ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example_rc ${STAGEDIR}${EXAMPLESDIR}/keylaunch.rc

.include <bsd.port.mk>
