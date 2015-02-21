# $FreeBSD$

PORTNAME=	innerspace
PORTVERSION=	0.2.0
PORTREVISION=	4
CATEGORIES=	x11 gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	InnerSpace-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep screensaver

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/InnerSpace.app/Resources/NickSpace.InnerSpace/NickSpace \
		${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/InnerSpace.app/Resources/Black.InnerSpace/Black \
		${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/InnerSpace.app/Resources/Boxes.InnerSpace/Boxes \
		${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/InnerSpace.app/InnerSpace

.include <bsd.port.mk>
