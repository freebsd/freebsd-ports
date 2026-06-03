PORTNAME=	durden
DISTVERSION=	0.6.3
CATEGORIES=	x11-wm
MASTER_SITES=	https://codeberg.org/letoram/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	hoanga@gmail.com
COMMENT=	Desktop Environment for Arcan
WWW=		https://durden.arcan-fe.com/

LICENSE=	BSD3CLAUSE # without fonts
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	arcan:multimedia/arcan

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} 's,/usr,${PREFIX},' ${WRKSRC}/distr/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/distr/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTNAME}" \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
