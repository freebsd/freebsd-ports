# $FreeBSD$

PORTNAME=	enventor
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	x11 enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/apps/${PORTNAME}/
DIST_SUBDIR=	enlightenment

MAINTAINER=	itbot@bk.ru
COMMENT=	Dynamic EDC Editor

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		fails to build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-06-06

LIB_DEPENDS=	libefl.so:devel/efl

USES=		compiler:c11 desktop-file-utils gmake libtool pkgconfig \
		tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libenventor.so.1.0.0

.include <bsd.port.mk>
