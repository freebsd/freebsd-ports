PORTNAME=	aclip
DISTVERSION=	0.6.2
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCH_WRKSRC=	${WRKSRC:H:H:H}
PATCHFILES+=	f1ff13a78c8a.patch:-p1 # https://github.com/letoram/arcan/pull/254

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Command line interface to Arcan clipboards

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
