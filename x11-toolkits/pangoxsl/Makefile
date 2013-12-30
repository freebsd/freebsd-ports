# Created by: James Earl
# $FreeBSD$

PORTNAME=	pangoxsl
PORTVERSION=	1.6.0.3
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/pangopdf/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implements Pango library with a PDF backend for PDF output

USES=		gmake pathfix pkgconfig
USE_GNOME=	pango
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool

CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
