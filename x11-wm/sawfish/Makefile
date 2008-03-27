# New ports collection makefile for:   sawfish
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-wm/sawfish/Makefile,v 1.5 2007/10/10 22:57:29 mezz Exp $
#

PORTNAME=	sawfish
PORTVERSION=	1.3.3
PORTEPOCH=	2
CATEGORIES=	x11-wm
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	sawmill
DIST_SUBDIR=	gnome2

MAINTAINER=	anray@FreeBSD.org
COMMENT=	Lisp configurable window manager

LIB_DEPENDS=	rep.13:${PORTSDIR}/lang/librep
BUILD_DEPENDS=	${LOCALBASE}/libexec/rep/${GNUHOST}/gui/gtk-2/gtk.so:${PORTSDIR}/x11-toolkits/rep-gtk2
RUN_DEPENDS=	${LOCALBASE}/libexec/rep/${GNUHOST}/gui/gtk-2/gtk.so:${PORTSDIR}/x11-toolkits/rep-gtk2

GNUHOST=	${ARCH}-pc-freebsd${OSREL:C/\..*//}
PLIST_SUB=	GNUHOST=${GNUHOST} VERSION=${PORTVERSION}

USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier gnomehack esound
USE_AUTOTOOLS=	autoconf:261:env automake:19:env libtool:15:env
WANT_GNOME=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes

CONFIGURE_SCRIPT=	autogen.sh
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share \
		--datadir=${PREFIX}/share \
		--enable-capplet \
		--disable-themer \
		--with-esd
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	${ARCH}-pc-freebsd${OSREL:C/\..*//}

INFO=		sawfish

post-patch:
	@${REINPLACE_CMD} -e 's|prog_name|program_name|g' \
	    	${WRKSRC}/src/main.c

.include <bsd.port.mk>
