# New ports collection makefile for:	libxklavier
# Date created:				31 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/libxklavier/Makefile,v 1.47 2009/03/21 04:28:11 marcus Exp $
#

PORTNAME=	libxklavier
PORTVERSION=	3.9
PORTEPOCH=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	SF/gswitchit/${PORTNAME}/${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An utility library to make XKB stuff easier

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
RUN_DEPENDS=	xkbcomp:${PORTSDIR}/x11/xkbcomp \
    		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USE_XORG=	x11 xkbfile
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack libxml2 glib20 ltverhack:12
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--disable-doxygen \
		--with-xkb-base=${LOCALBASE}/share/X11/xkb \
		--with-xkb-bin-base=${LOCALBASE}/bin \
		--with-xmodmap-base=${LOCALBASE}/share/xmodmap \
		--disable-gtk-doc \
		--with-html-dir=${GNOME_HTML_DIR}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|== "yes|= "yes|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
