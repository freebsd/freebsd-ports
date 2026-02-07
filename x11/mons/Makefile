PORTNAME=	mons
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	rob@sarcasticadmin.com
COMMENT=	POSIX shell script to quickly manage displays using XRandR
WWW=		https://github.com/Ventto/mons

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	help2man:misc/help2man
RUN_DEPENDS=	xrandr:x11/xrandr

USE_GITHUB=	yes
GH_ACCOUNT=	Ventto
GH_PROJECT=	libshlist:libshlist
GH_TAGNAME=	1cbcdcb:libshlist
GH_SUBDIR=	libshlist:libshlist

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/mons

post-install-DOCS-on:
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "README.md img/" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
