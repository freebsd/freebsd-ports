# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libfm-extra
PORTVERSION=	1.2.3
CATEGORIES=	x11
MASTER_SITES=	SF/pcmanfm/PCManFM%20%2B%20Libfm%20%28tarball%20release%29/LibFM/
DISTNAME=	libfm-${PORTVERSION}

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Core library of PCManFM file manager

LICENSE=	LGPL21

USES=		gmake libtool pathfix pkgconfig tar:xz gettext-tools
USE_GNOME=	glib20 intltool intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

WRKSRC=	${WRKDIR}/libfm-${PORTVERSION}

EXTRA_PATCHES+=	${.CURDIR}/../libfm/files/patch-configure

CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc --with-extra-only \
	--disable-static \
	--disable-nls

.include <bsd.port.mk>
