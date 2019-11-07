# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	skippy-xd
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	x11-wm

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Full-screen Expose-style standalone task switcher for X11

LICENSE=	GPLv2

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png

USES=		gmake jpeg pkgconfig xorg
USE_XORG=	x11 xcomposite xdamage xext xfixes xft xinerama xrender

USE_GITHUB=	yes
GH_ACCOUNT=	richardgv
GH_TAGNAME=	397216c

MAKE_ARGS=	SKIPPYXD_VERSION=${PORTVERSION}-git-${GH_TAGNAME}-2015-02-24

PLIST_FILES=	bin/skippy-xd \
		@sample\ etc/xdg/skippy-xd.rc.sample
PORTDOCS=	CHANGELOG

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
