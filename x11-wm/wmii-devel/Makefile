# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmii
DISTVERSION=	3.9.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://dl.suckless.org/wmii/ GOOGLE_CODE
DISTNAME=	${PORTNAME}+ixp-${DISTVERSION}
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic, minimalist window manager for X11

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	wmii-3.6*

LIB_DEPENDS=	libixp.so:${PORTSDIR}/devel/libixp

USES=		pkgconfig tar:tbz
USE_XORG=	x11 xext xrandr xrender xinerama xft

MAKE_ARGS=	PREFIX="${PREFIX}" INCLUDE="${LOCALBASE}/include" \
		CC="${CC} -c" LD="${CC}" LIBIXP="-lixp" STATIC="" \
		MAN="${MANPREFIX}/man" DOC="${DOCSDIR}"
MAKE_ENV=	noisycc=1	# unmute build commands, useful for logs

OPTIONS_DEFINE=	DOCS

post-patch:
# Link against `devel/libixp' from ports and drop extraneous build options
	@${REINPLACE_CMD} -e '/libixp/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/usr/lib,${LOCALBASE}/lib, ; /^CFLAGS +=/d' \
		${WRKSRC}/config.mk

.include <bsd.port.mk>
