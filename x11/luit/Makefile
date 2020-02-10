# $FreeBSD$

PORTNAME=	luit
PORTVERSION=	20190106
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.invisible-island.net/luit/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Locale and ISO 2022 support for Unicode terminals

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/fonts/encodings/encodings.dir:x11-fonts/encodings
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		iconv localbase:ldflags tar:tgz pkgconfig xorg
USE_XORG=	ice x11 xt

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--x-libraries=${LOCALBASE}/lib \
		--x-includes=${LOCALBASE}/include \
		--with-encodings-dir=${LOCALBASE}/share/fonts/encodings/encodings.dir \
		--with-locale-alias=${LOCALBASE}/lib/X11/locale/locale.alias \
		--with-pkg-config=${LOCALBASE}/bin/pkg-config \

PLIST_FILES=	bin/luit man/man1/luit.1.gz

.include <bsd.port.mk>
