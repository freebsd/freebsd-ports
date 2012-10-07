# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	waimea
PORTVERSION=	0.5.1
PORTREVISION=	6
CATEGORIES=	x11-wm
MASTER_SITES=	http://dev.gentoo.org/~nixphoeni/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	danfe

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	An X11 window manager designed for maximum efficiency

DEPRECATED=	Development ceased
EXPIRATION_DATE=	2012-11-05

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		cairo.2:${PORTSDIR}/graphics/cairo

LATEST_LINK=	${PORTNAME}-devel

USE_AUTOTOOLS=	automake:env
USE_GMAKE=	yes
USE_ICONV=	yes
USE_XORG=	x11
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	PNG SVG THREADS
OPTIONS_DEFAULT=	PNG SVG

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=	--disable-png
.endif

.if ${PORT_OPTIONS:MSVG}
LIB_DEPENDS+=	svg-cairo.1:${PORTSDIR}/graphics/libsvg-cairo
.else
CONFIGURE_ARGS+=	--disable-svg
MAKE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-thread
.endif

MAN1=		waimea.1

post-extract:
.for f in config.guess config.sub depcomp install-sh mkinstalldirs missing
	@${LN} -fs ${AUTOMAKE_DIR}/${f} ${WRKSRC}/config/${f}
.endfor

.include <bsd.port.mk>
