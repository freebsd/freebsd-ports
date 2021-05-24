PORTNAME=	ztoolkit
DISTVERSION=	0.1.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://git.zrythm.org/zrythm/ztoolkit/archive/ # .../v${DISTVERSION}.tar.gz&dummy=/ doesn't work with Gitea
DISTNAME=	v${DISTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GUI toolkit heavily inspired by GTK

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome meson pkgconfig xorg
USE_GNOME=	cairo
USE_XORG=	x11

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
