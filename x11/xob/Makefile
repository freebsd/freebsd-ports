PORTNAME=	xob
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Lightweight overlay volume (or anything) bar for the X Window System

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libconfig.so:devel/libconfig

USES=		compiler:c11 gmake pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	florentc
USE_XORG=	x11

PORTDOCS=	CHANGELOG.md CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/xob \
		"@sample ${ETCDIR}/styles.cfg.sample" \
		share/man/man1/xob.1.gz

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
