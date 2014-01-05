# Created by: Hendrik Scholz <hendrik@scholz.net>
# $FreeBSD$

PORTNAME=	fbdesk
PORTVERSION=	1.4.1
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	http://fluxbox.sourceforge.net/download/ \
		GENTOO/distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fluxbox utility to create and manage icons on the desktop

LICENSE=	MIT

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	IMLIB2 DOCS
OPTIONS_DEFAULT=	IMLIB2

USE_XORG=	xext xft xpm xrender
USES=		pkgconfig
WANT_EFL=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	ChangeLog INSTALL README
PLIST_FILES=	bin/fbdesk

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMLIB2}
USE_EFL+=	imlib2
.else
CONFIGURE_ARGS+=	--disable-imlib2
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
