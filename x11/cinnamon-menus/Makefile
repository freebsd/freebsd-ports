# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/x11/cinnamon-menus/Makefile 19579 2014-04-26 07:10:16Z kwm $

PORTNAME=	cinnamon-menus
PORTVERSION=	2.2.0
CATEGORIES=	x11 gnome
MASTER_SITES=	http://github.com/linuxmint/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for cinnamon

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		${LOCALBASE}/libdata/pkgconfig/xkeyboard-config.pc:${PORTSDIR}/x11/xkeyboard-config \
		${LOCALBASE}/libdata/pkgconfig/xkbfile.pc:${PORTSDIR}/x11/libxkbfile
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xkeyboard-config.pc:${PORTSDIR}/x11/xkeyboard-config \
		${LOCALBASE}/libdata/pkgconfig/xkbfile.pc:${PORTSDIR}/x11/libxkbfile

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_GNOME=	gnomehier gnomeprefix gtk30 intlhack introspection:build
USE_PYTHON=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf automake libtool
PATHFIX_MAKEFILEIN=	Makefile.am
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${SED} -e 's|/usr/local|${LOCALBASE}|g' \
		< ${FILESDIR}/KDE.directory > ${WRKSRC}/KDE.directory

post-install:
	@${INSTALL_DATA} ${WRKSRC}/KDE.directory \
		${STAGEDIR}${PREFIX}/share/desktop-directories

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
