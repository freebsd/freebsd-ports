PORTNAME=	waycheck
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Simple GUI that displays the protocols implemented by a Wayland compositor
WWW=		https://gitlab.freedesktop.org/serebit/waycheck

LICENSE=		APACHE20 CC0-1.0
LICENSE_COMB=		multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSES/Apache-2.0.txt
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSES/CC0-1.0.txt

LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		meson pkgconfig qt:6

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org/
GL_ACCOUNT=	serebit

USE_QT=		base wayland

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/dev.serebit.Waycheck.desktop \
		share/icons/hicolor/scalable/apps/dev.serebit.Waycheck.svg \
		share/metainfo/dev.serebit.Waycheck.metainfo.xml

.include <bsd.port.mk>
