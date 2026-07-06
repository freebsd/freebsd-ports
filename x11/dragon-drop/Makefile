PORTNAME=	dragon-drop
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	x11

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Drag and drop source/target for X or Wayland
WWW=		https://github.com/mwh/dragon

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		gnome pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	mwh
GH_PROJECT=	dragon

USE_GNOME=	gtk30

MAKE_ENV=	DESTDIR="${STAGEDIR}" \
		NAME="${PORTNAME}"

PLIST_FILES=	bin/dragon-drop \
		share/man/man1/dragon-drop.1.gz

.include <bsd.port.mk>
