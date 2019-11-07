# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmii
PORTVERSION=	3.9.2
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://dl.suckless.org/wmii/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}+ixp-${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Dynamic, minimalist window manager for X11

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libixp.so:devel/libixp

CONFLICTS=	wmii-[0-9]*

USES=		pkgconfig python:run shebangfix tar:tbz xorg
SHEBANG_FILES=	alternative_wmiircs/python/wmiirc
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

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/LICENSE
.for f in bin/wimenu bin/wmii bin/wmii9menu bin/wmiir lib/libwmii_hack.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${f}
.endfor

.include <bsd.port.mk>
