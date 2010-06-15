# New ports collection makefile for:	Window Manager Improved 2 (beta)
# Date created:				02 Jun 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmii
DISTVERSION=	3.9.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://dl.suckless.org/wmii/
DISTNAME=	wmii+ixp-${DISTVERSION}
EXTRACT_SUFX=	.tbz

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A dynamic, minimalist window manager for X11

LIB_DEPENDS=	ixp.1:${PORTSDIR}/devel/libixp

CONFLICTS=	wmii-3.6*
LATEST_LINK=	${PORTNAME}-devel

USE_BZIP2=	yes
USE_XORG=	x11 xext xrandr xrender xinerama xft

MAKE_ARGS=	PREFIX="${PREFIX}" INCLUDE="${LOCALBASE}/include" \
		CC="${CC} -c" LD="${CC}" LIBIXP="-lixp" STATIC="" \
		MAN="${MANPREFIX}/man" DOC="${DOCSDIR}"
MAKE_ENV=	noisycc=1	# unmute build commands, useful for logs

MAN1=		wimenu.1 wmii9menu.1 wmii.1 wmiir.1

post-patch: .SILENT
# Link against `devel/libixp' from ports and drop extraneous build options
	${REINPLACE_CMD} -e '/libixp/d' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,/usr/lib,${LOCALBASE}/lib, ; /^CFLAGS +=/d' \
		${WRKSRC}/config.mk
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/doc/d' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e '/DOCDIR/s,$$(INSTALL),:,' ${WRKSRC}/mk/common.mk
.endif

.include <bsd.port.mk>
