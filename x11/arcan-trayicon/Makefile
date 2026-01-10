PORTNAME=	arcan
DISTVERSION=	0.7.1
CATEGORIES=	x11
MASTER_SITES=	https://codeberg.org/letoram/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
PKGNAMESUFFIX=	-trayicon

MAINTAINER=	hoanga@gmail.com
COMMENT=	Generic wrapper for registering Arcan clients as tray icons
WWW=		https://arcan-fe.com/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC:H:H:H}/data/distr/LICENSE.BSD

LIB_DEPENDS=	libarcan_shmif.so:multimedia/arcan \
		libarcan_tui.so:multimedia/arcan

USES=		compiler:c11 meson pkgconfig
WRKSRC=		${WRKDIR}/${PORTNAME}
WRKSRC_SUBDIR=	src/tools/${PKGNAMESUFFIX:S/-//}
PLIST_FILES=	bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.mk>
