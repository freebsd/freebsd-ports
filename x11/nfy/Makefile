PORTNAME=	nfy
DISTVERSION=	0.1
CATEGORIES=	x11
MASTER_SITES=	https://ftp.christosmarg.xyz/${PORTNAME}/

MAINTAINER=	christos@christosmarg.xyz
COMMENT=	Minimal and daemonless notification program for X

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
#TEST_DEPENDS=	${LOCALBASE}/libexec/atf-check:devel/kyua

USES=		xorg
USE_XORG=	x11 xft xrandr

MAKE_ARGS=	CC="${CC}" \
		FREETYPEINC="${LOCALBASE}/include/freetype2" \
		PREFIX="${PREFIX}" \
		VERSION="${PORTVERSION}" \
		X11INC="${LOCALBASE}/include" \
		X11LIB="${LOCALBASE}/lib"

PLIST_FILES=	bin/nfy \
		share/man/man1/nfy.1.gz

pre-everything:
	@${ECHO_MSG} "Build nfy with your own config.h using the NFY_CONF option:"
	@${ECHO_MSG} "make NFY_CONF=/path/to/nfy/config.h install clean"

.if exists(${NFY_CONF})
post-extract:
	@${ECHO_MSG} "Creating symlink: config.h -> ${NFY_CONF}"
	${LN} -fs "${NFY_CONF}" ${WRKSRC}/config.h
.endif

post-configure:
	@${REINPLACE_CMD} -E \
		-e "s|(CFLAGS[[:space:]]*)= |\1+= |" \
		-e "s|(CPPFLAGS[[:space:]]*)= |\1+= |" \
		-e "s|(LDFLAGS[[:space:]]*)= |\1+= |" \
		${WRKSRC}/config.mk

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nfy

do-test:
	${LOCALBASE}/libexec/atf-check -s exit:1 -e match:"nfy-${PORTVERSION}" \
		${STAGEDIR}${PREFIX}/bin/nfy -v

.include <bsd.port.mk>
