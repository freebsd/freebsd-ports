PORTNAME=	shikane
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
PORTREVISION=	11
CATEGORIES=	x11 wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic output configuration tool for Wayland compositors
WWW=		https://gitlab.com/w0lff/shikane

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITLAB=	yes
GL_ACCOUNT=	w0lff
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}ctl

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_EXCLUDE_i386=	MANPAGES # https://github.com/haskell-foundation/foundation/issues/565

MANPAGES_BUILD_DEPENDS=	bash:shells/bash \
			pandoc:textproc/hs-pandoc
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz \
			share/man/man1/${PORTNAME}ctl.1.gz \
			share/man/man5/${PORTNAME}.5.gz

do-build-MANPAGES-on:
	${WRKSRC}/scripts/build-docs.sh man

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/build/man/*.1.gz \
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/build/man/*.5.gz \
		${STAGEDIR}${PREFIX}/share/man/man5

.include <bsd.port.mk>
