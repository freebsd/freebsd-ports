PORTNAME=	pmenu
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
CATEGORIES=	x11

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Pie menu for X

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libImlib2.so:graphics/imlib2

USES=		localbase xorg
USE_GITHUB=	yes
GH_ACCOUNT=	phillbush
USE_XORG=	x11 xext xft xinerama xrender

MAKE_ARGS=	FREETYPEINC="${LOCALBASE}/include/freetype2" \
		PREFIX="${PREFIX}"

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
