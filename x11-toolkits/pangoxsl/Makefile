# New ports collection makefile for:	pangoxsl
# Date created:		1 January 2005
# Whom:			James Earl
#
# $FreeBSD$
#

PORTNAME=	pangoxsl
PORTVERSION=	1.6.0.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pangopdf

MAINTAINER=	chero7@telus.net
COMMENT=	Implements Pango library with a PDF backend for PDF output

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pango
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
