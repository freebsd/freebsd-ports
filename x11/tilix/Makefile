# $FreeBSD$

PORTNAME=	tilix
PORTVERSION=	1.9.3
CATEGORIES=	x11

PATCH_DIST_STRIP=-p1
PATCH_SITES=	https://patch-diff.githubusercontent.com/raw/gnunn1/tilix/pull/
PATCHFILES=	1733.diff

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Tiling terminal emulator using GTK+ 3

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ldc2:lang/ldc \
		po4a-translate:textproc/po4a \
		${LOCALBASE}/libdata/pkgconfig/vted-3.pc:x11-toolkits/gtkd

USES=		autoreconf gettext gmake gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	gnunn1
GNU_CONFIGURE=	yes
USE_GNOME=	vte3
GLIB_SCHEMAS=	com.gexperts.Tilix.gschema.xml
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
