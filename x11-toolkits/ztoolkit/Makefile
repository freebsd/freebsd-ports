PORTNAME=	ztoolkit
DISTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://git.zrythm.org/zrythm/ztoolkit/archive/ # .../v${DISTVERSION}.tar.gz&dummy=/ doesn't work with Gitea
DISTNAME=	v${DISTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GUI toolkit heavily inspired by GTK

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gnome meson pkgconfig xorg
USE_GNOME=	cairo librsvg2
USE_XORG=	x11

WRKSRC=		${WRKDIR}/${PORTNAME}

MESON_ARGS=	-Denable_rsvg=true

.include <bsd.port.mk>
