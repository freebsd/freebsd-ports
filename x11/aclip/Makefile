PORTNAME=	aclip
DISTVERSION=	0.6.3
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Command line interface to Arcan clipboards
WWW=		https://arcan-fe.com/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC:H:H:H}/data/distr/LICENSE.BSD

LIB_DEPENDS=	libarcan_shmif_ext.so:multimedia/arcan

USES=		cmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	letoram
GH_PROJECT=	arcan
WRKSRC_SUBDIR=	src/tools/${PORTNAME}
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
