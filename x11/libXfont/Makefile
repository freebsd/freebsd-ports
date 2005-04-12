# New ports collection makefile for:   libXfont
# Date Created:			29 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXfont
PORTVERSION=	1.4.2
CATEGORIES=	x11
MASTER_SITES=	http://freedesktop.org/~ajax/xlibs-release/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X font libary

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig \
		${X11BASE}/libdata/pkgconfig/xproto.pc:${PORTSDIR}/x11/xproto
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

CONFLICTS=	XFree86-libraries-* xorg-libraries-*

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-freetype
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack pkgconfig

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xorg
PLIST_SUB+=	NEWMTREE=""
.else
PLIST_SUB+=	NEWMTREE="@comment "
.endif

.include <bsd.port.post.mk>
