PORTNAME=	shikane
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	4
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Dynamic output configuration tool for Wayland compositors
WWW=		https://gitlab.com/w0lff/shikane

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITLAB=	yes
GL_ACCOUNT=	w0lff
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_EXCLUDE_i386=	MANPAGES # https://github.com/haskell-foundation/foundation/issues/565

MANPAGES_BUILD_DEPENDS=	bash:shells/bash \
			pandoc:textproc/hs-pandoc
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz \
			share/man/man5/${PORTNAME}.5.gz

do-build-MANPAGES-on:
	${WRKSRC}/scripts/build-docs.sh man

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/build/${PORTNAME}.1.gz \
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/build/${PORTNAME}.5.gz \
		${STAGEDIR}${PREFIX}/share/man/man5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
