PORTNAME=	durden
DISTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop Environment for Arcan
WWW=		https://durden.arcan-fe.com/

LICENSE=	BSD3CLAUSE # without fonts
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	arcan:multimedia/arcan

USE_GITHUB=	yes
GH_ACCOUNT=	letoram
NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} 's,/usr,${PREFIX},' ${WRKSRC}/distr/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/distr/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTNAME}" \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
