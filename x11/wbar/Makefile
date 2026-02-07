PORTNAME=	wbar
PORTVERSION=	2.3.4
PORTREVISION=	11
CATEGORIES=	x11
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/${PORTNAME}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Simple and highly customizable quick launch bar
WWW=		https://code.google.com/archive/p/wbar/

LICENSE=	GPLv3

BUILD_DEPENDS=	intltool-update:textproc/intltool
LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		compiler:c++11-lang gettext gmake gnome pkgconfig tar:tgz

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--exec-prefix=${PREFIX}
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB+=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,}

OPTIONS_DEFINE=		NLS WBARCONFIG
OPTIONS_DEFAULT=	WBARCONFIG
OPTIONS_SUB=		yes

WBARCONFIG_DESC=	Build the GTK configuration interface

NLS_CONFIGURE_ENABLE=	nls
NLS_LIBS=		-lintl

WBARCONFIG_USE=			GNOME=libglade2
WBARCONFIG_CONFIGURE_ENABLE=	wbar-config

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/wbar.d/wbar.desktop ${STAGEDIR}${DESKTOPDIR}/wbar.desktop

.include <bsd.port.mk>
