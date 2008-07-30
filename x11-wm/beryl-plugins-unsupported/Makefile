# New ports collection makefile for:	beryl-plugins-unsupported
# Date created:		2007-06-08
# Whom:			Robert Noland <rnoland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	beryl-plugins-unsupported
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.beryl-project.org/${PORTVERSION}/

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	Additional Plugins for Beryl Composite/Window Manager

# XXX - Might depends on graphics/libsvg-cairo instead.
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/beryl.pc:${PORTSDIR}/x11-wm/beryl-core
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GL=		yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 librsvg2
USE_XORG=	glproto
USE_GETTEXT=	yes
USE_LDCONFIG=	yes

DEPRECATED=	No longer supported - Use compiz
EXPIRATION_DATE=	2008-08-02

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
