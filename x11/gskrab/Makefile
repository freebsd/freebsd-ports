# $FreeBSD$

PORTNAME=	gskrab
PORTVERSION=	0.0.1
PORTREVISION=	7
CATEGORIES=	x11 gnustep
MASTER_SITES=	http://organact.mine.nu/~wolfgang/gskrab/
DISTNAME=	GSKrab-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep Keyboard Grabber

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnustep
USE_GNUSTEP=	back build
USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

ADDITIONAL_LIB_DIRS+=	-L${WRKSRC}/GSKrabFramework/GSKrab.framework/Versions/Current

post-patch:
	@${REINPLACE_CMD} -e "/GNUSTEP_INSTALLATION_DIR/d" ${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Tools/gsks \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Frameworks/GSKrab.framework/Versions/0/libGSKrab.so

.include <bsd.port.mk>
