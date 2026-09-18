PORTNAME=	pmenu
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.1
CATEGORIES=	x11
PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
# aee4d6665c9208a25b3d75410d6a485d74575f68 --> https://github.com/phillbush/pmenu/pull/19
# e3efbb5923f638b38087a3f616906d9d4fdaf6f2 --> https://github.com/phillbush/pmenu/pull/20
PATCHFILES=	aee4d6665c9208a25b3d75410d6a485d74575f68.patch:-p1 \
		e3efbb5923f638b38087a3f616906d9d4fdaf6f2.patch:-p1

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Pie menu for X
WWW=		https://github.com/phillbush/pmenu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libImlib2.so:graphics/imlib2

USES=		xorg
USE_GITHUB=	yes
GH_ACCOUNT=	phillbush
USE_XORG=	x11 xext xft xinerama xrender

MAKE_ARGS=	FREETYPEINC="${LOCALBASE}/include/freetype2" \
		LOCALINC="${LOCALBASE}/include" \
		LOCALLIB="${LOCALBASE}/lib" \
		PREFIX="${PREFIX}" \
		X11INC="${LOCALBASE}/include/xorg" \
		X11LIB="${LOCALBASE}/lib/xorg"

CPPFLAGS+=	-D_XOPEN_SOURCE=700

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

PORTEXAMPLES=	${PORTNAME}.sh

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
