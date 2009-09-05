# New ports collection makefile for:   sawfish
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-wm/sawfish/Makefile,v 1.5 2007/10/10 22:57:29 mezz Exp $
#

PORTNAME=	sawfish
PORTVERSION=	1.5.0
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	x11-wm
MASTER_SITES=	SF/sawmill/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	anray@FreeBSD.org
COMMENT=	Lisp configurable window manager

LIB_DEPENDS=	rep.13:${PORTSDIR}/lang/librep \
		audiofile.0:${PORTSDIR}/audio/libaudiofile \
		cairo.2:${PORTSDIR}/graphics/cairo
BUILD_DEPENDS=	${LOCALBASE}/libexec/rep/${GNUHOST}/gui/gtk-2/gtk.so:${PORTSDIR}/x11-toolkits/rep-gtk2
RUN_DEPENDS=	${LOCALBASE}/libexec/rep/${GNUHOST}/gui/gtk-2/gtk.so:${PORTSDIR}/x11-toolkits/rep-gtk2

GNUHOST=	${ARCH}-pc-freebsd${OSREL:C/\..*//}
PLIST_SUB=	GNUHOST=${GNUHOST} VERSION=${PORTVERSION}

USE_XORG=	ice sm x11 xft xinerama xrandr
USE_GMAKE=	yes
USE_GNOME=	pango gtk20 glib20 esound
USE_BZIP2=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share \
		--datadir=${PREFIX}/share
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	${ARCH}-pc-freebsd${OSREL:C/\..*//}

INFO=		sawfish

post-patch:
	@${REINPLACE_CMD} -e 's|prog_name|program_name|g' \
	${WRKSRC}/src/main.c
	@${MKDIR} ${WRKSRC}/m4

.include <bsd.port.mk>
