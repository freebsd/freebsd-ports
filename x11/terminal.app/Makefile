PORTNAME=	terminal.app
PORTVERSION=	0.9.9
PORTREVISION=	6
CATEGORIES=	x11 gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	Terminal-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal Emulator for GNUstep
WWW=		https://www.nongnu.org/backbone/

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnustep iconv
USE_GNUSTEP=	back build

MAKE_ARGS+=	Terminal_TOOL_LIBS='${ICONV_LIB} -lutil'

post-patch:
	@${REINPLACE_CMD} -e 's,^NSString \*,extern &,' \
		${WRKSRC}/TerminalWindow.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Terminal.app/Terminal

.include <bsd.port.mk>
