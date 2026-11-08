PORTNAME=	j4-dmenu-desktop
DISTVERSIONPREFIX=	r
DISTVERSION=	3.2
CATEGORIES=	x11

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Fast desktop menu (i3-dmenu-desktop replacement)
WWW=		https://github.com/enkore/j4-dmenu-desktop

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}crazy-complete>=0:shells/py-crazy-complete@${PY_FLAVOR}

LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog

USES=		compiler:c++17-lang meson pkgconfig python:env
USE_GITHUB=	yes
GH_ACCOUNT=	enkore

MESON_ARGS=	-Denable-tests=false \
		-Dgenerate-shell-completions=enabled \
		-Doverride-version="${PKGVERSION}"

PLIST_FILES=	bin/j4-dmenu-desktop \
		share/bash-completion/completions/j4-dmenu-desktop \
		share/fish/vendor_completions.d/j4-dmenu-desktop.fish \
		share/man/man1/j4-dmenu-desktop.1.gz \
		share/zsh/site-functions/_j4-dmenu-desktop
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/j4-dmenu-desktop.1 ${STAGEDIR}${PREFIX}/share/man/man1/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
