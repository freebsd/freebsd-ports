PORTNAME=	jewel
PORTVERSION=	0.12.41
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	http://mjr.towers.org.uk/comp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window manager based on aewm++
WWW=		https://mjr.towers.org.uk/xwinman.html #jewel

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Last upstream release was in 2004
EXPIRATION_DATE=	2024-01-19

USES=		compiler gmake xorg
USE_CXXSTD=	c++14
USE_XORG=	x11 xext xpm

MAKE_ARGS=	CFLAGS="${CXXFLAGS}"
ALL_TARGET=	all

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

PORTDOCS=	Changelog Changelog.DLR Changelog.jewel INSTALL README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -i '' -e 's|g++|${CXX}|g; s|gcc|${CC}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jewel ${STAGEDIR}${PREFIX}/bin/jewel
	${INSTALL_PROGRAM} ${WRKSRC}/goodies/appbar/appbar ${STAGEDIR}${PREFIX}/bin/jewel-appbar
	${INSTALL_PROGRAM} ${WRKSRC}/goodies/fspanel/fspanel ${STAGEDIR}${PREFIX}/bin/jewel-fspanel
	${INSTALL_PROGRAM} ${WRKSRC}/goodies/setrootimage/setrootimage ${STAGEDIR}${PREFIX}/bin/jewel-setrootimage
	${INSTALL_PROGRAM} ${WRKSRC}/goodies/xsession/xsession ${STAGEDIR}${PREFIX}/bin/jewel-xsession
	${INSTALL_MAN} ${WRKSRC}/jewel.1x ${STAGEDIR}${PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for ii in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
