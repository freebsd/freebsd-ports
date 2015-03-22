# $FreeBSD$

PORTNAME=	gskrab
PORTVERSION=	0.0.1
PORTREVISION=	5
CATEGORIES=	x11 gnustep
MASTER_SITES=	http://organact.mine.nu/~wolfgang/gskrab/
DISTNAME=	GSKrab-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep Keyboard Grabber

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

ADDITIONAL_LIB_DIRS+=	-L${WRKSRC}/GSKrabFramework/GSKrab.framework/Versions/Current

post-patch:
	@${REINPLACE_CMD} -e "/GNUSTEP_INSTALLATION_DIR/d" ${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Tools/gsks \
		${STAGEDIR}${PREFIX}/GNUstep/Local/Library/Frameworks/GSKrab.framework/Versions/0/libGSKrab.so

.include <bsd.port.mk>
