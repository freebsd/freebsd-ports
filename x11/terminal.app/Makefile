# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	terminal.app
PORTVERSION=	0.9.9
PORTREVISION=	3
CATEGORIES=	x11 gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	Terminal-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal Emulator for GNUstep

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_13=	duplicate symbol: TerminalWindowNoMoreActiveWindowsNotification
BROKEN_FreeBSD_14=	duplicate symbol: TerminalWindowNoMoreActiveWindowsNotification

USES=		gnustep iconv
USE_GNUSTEP=	back build

MAKE_ARGS+=	Terminal_TOOL_LIBS='${ICONV_LIB} -lutil'

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Terminal.app/Terminal

.include <bsd.port.mk>
