# Created by: James Earl
# $FreeBSD$

PORTNAME=	pangoxsl
PORTVERSION=	1.6.0.3
PORTREVISION=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/pangopdf/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implements Pango library with a PDF backend for PDF output

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake gnome libtool pathfix pkgconfig
USE_GNOME=	pango
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
