# New ports collection makefile for:	Waimea
# Date created:				03 Mar 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	waimea
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://dev.gentoo.org/~nixphoeni/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	danfe

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An X11 window manager designed for maximum efficiency

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		cairo.2:${PORTSDIR}/graphics/cairo

LATEST_LINK=	${PORTNAME}-devel

USE_AUTOTOOLS=	automake:19:env
USE_GMAKE=	yes
USE_ICONV=	yes
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	PNG "Enable PNG support" On \
		SVG "Enable SVG support" On \
		THREAD "Enable threading support" Off

.include <bsd.port.pre.mk>

.if defined(WITH_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=	--disable-png
.endif

.if defined(WITH_SVG)
LIB_DEPENDS+=	svg-cairo.1:${PORTSDIR}/graphics/libsvg-cairo
.else
CONFIGURE_ARGS+=	--disable-svg
MAKE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.endif

.if defined(WITH_THREAD)
CONFIGURE_ARGS+=	--enable-thread
.endif

MAN1=		waimea.1

post-extract:
.for f in config.guess config.sub depcomp install-sh mkinstalldirs missing
	@${LN} -fs ${AUTOMAKE_DIR}/${f} ${WRKSRC}/config/${f}
.endfor

.include <bsd.port.post.mk>
