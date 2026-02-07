PORTNAME=	xwinwrap
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9
CATEGORIES=	x11

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	XWinWrap replace a desktop background with a movie or screensaver

LICENSE=	NOVELL
LICENSE_NAME=	Novell License
LICENSE_FILE=	${WRKSRC}/xwinwrap.c
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		localbase:ldflags shebangfix xorg
USE_GITHUB=	yes
GH_ACCOUNT=	mmhobi7
USE_XORG=	x11 xorgproto xrender xext

SHEBANG_FILES=	examples/mint_auto_start_example.sh
bash_CMD=	${SH}

LIBS+=		-lX11 -lXext -lXrender

PLIST_FILES=	bin/${PORTNAME} \
		${EXAMPLESDIR}/mint_auto_start_example.sh

do-build:
	${SETENVI} ${MAKE_ENV} ${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} \
		-o ${WRKDIR}/xwinwrap ${WRKSRC}/xwinwrap.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/xwinwrap ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/mint_auto_start_example.sh \
		${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
